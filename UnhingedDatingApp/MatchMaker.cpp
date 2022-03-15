#include "provided.h"
#include "RadixTree.h"
#include "MemberDatabase.h"
#include "PersonProfile.h"
#include "AttributeTranslator.h"
#include "MatchMaker.h"

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) {
	m_db = mdb;
	m_at = at;
}

MatchMaker::~MatchMaker() {

}

vector<EmailCount> MatchMaker::IdentifyRankedMatches(string email, int threshold) const {
	PersonProfile person = *(m_db.GetMemberByEmail(email));
	unordered_set<string> compatiblePairs; // stores all compatible pairs for a member
	for (int i = 0; i < person.GetNumAttValPairs(); i++) {
		AttValPair currentPair;
		if (person.GetAttVal(i, currentPair)) {
			vector<AttValPair> pairs = m_at.FindCompatibleAttValPairs(currentPair);
			for (const auto& pair : pairs) {
				compatiblePairs.insert(pair.attribute + "," + pair.value);
			}
		}
	}

	unordered_map<string, int> matchingMembers; // contains all compatible members and the number of compatible pairs they have
	for (unordered_set<string>::iterator it = compatiblePairs.begin(); it != compatiblePairs.end(); it++) {
		AttValPair input(it->substr(0, it->find(',')), it->substr(it->find(',') + 1));
		vector<string> members = m_db.FindMatchingMembers(input);
		for (const auto& member : members) {
			unordered_map<string, int>::iterator it = matchingMembers.find(member);
			if (it != matchingMembers.end()) {
				it->second = it->second + 1;
			}
			else {
				matchingMembers.insert({ member, 1 });
			}
		}
	}
	
	for (unordered_map<string, int>::iterator it = matchingMembers.begin(); it != matchingMembers.end(); it++) {
		if (it->second > threshold) {
			cout << it->first << endl;
		}
	}
	return {};
}