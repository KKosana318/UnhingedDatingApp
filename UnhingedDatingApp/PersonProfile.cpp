#include "PersonProfile.h"
#include <iterator>

using namespace std;

PersonProfile::PersonProfile(string name, string email) {
	m_name = name;
	m_email = email;
	m_numPairs = 0;
}

PersonProfile::~PersonProfile() {

}

string PersonProfile::GetName() const {
	return m_name;
}

string PersonProfile::GetEmail() const {
	return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval) {
	vector<string>* result = m_attvals.search(attval.attribute);
	if (result == nullptr) {
		m_attvals.insert(attval.attribute, { attval.value });
		m_numPairs++;
		m_list.push_back(attval);
	}
	else {
		for (vector<string>::iterator i = result->begin(); i != result->end(); i++) {
			if (*i == attval.value) {
				return;
			}
		}

		result->push_back(attval.value);
		m_list.push_back(attval);
		m_numPairs++;
	}
}

int PersonProfile::GetNumAttValPairs() const {
	return m_numPairs;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
	attval = m_list[attribute_num];
	return true;
}



