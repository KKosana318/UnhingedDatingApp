#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "MemberDatabase.h"
#include "PersonProfile.h"

using namespace std;

MemberDatabase::MemberDatabase() {

}

MemberDatabase::~MemberDatabase() {

}

bool MemberDatabase::LoadDatabase(string filename) {
	ifstream members(filename);
	if (!members) {
		return false;
	}
	while (true) {
		string name, email, numPairsStr;
		if (!getline(members, name)) {
			break;
		}
		getline(members, email);
		getline(members, numPairsStr);

		int numPairs = stoi(numPairsStr);
		PersonProfile* currentPerson = new PersonProfile(name, email);

		PersonProfile** personPtr = m_emailsToPersons.search(email);

		PersonProfile* person = nullptr;
		if (personPtr != nullptr) {
			person = *personPtr;
		}
		if (person == nullptr) {
			m_emailsToPersons.insert(email, currentPerson);
		}
		else {
			return false;
		}

		while (numPairs--) {

			string pair;
			getline(members, pair);
			int split = pair.find(',');
			string first = pair.substr(0, split);
			string second = pair.substr(split + 1);

			currentPerson->AddAttValPair(AttValPair(first, second));
			
			vector<string>* emails = m_pairsToEmails.search(pair);
			if (emails == nullptr) {
				m_pairsToEmails.insert(pair, { email });
			}
			else {
				emails->push_back(email);
			}
		}

		getline(members, name); // skips blank line
	}

	return true;
}

vector<string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const {
	vector<string>* matches = m_pairsToEmails.search(input.attribute + "," + input.value);
	if (matches == nullptr) {
		return {};
	}

	return *matches;
}

const PersonProfile* MemberDatabase::GetMemberByEmail(string email) const {
	return *(m_emailsToPersons.search(email));
}