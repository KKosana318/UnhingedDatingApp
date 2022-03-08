#include "PersonProfile.h"

using namespace std;

PersonProfile::PersonProfile(string name, string email) {
	m_name = name;
	m_email = email;
	m_numPairs = 0;
}
PersonProfile::~PersonProfile() {

}
string PersonProfile::getName() {
	return m_name;
}
string PersonProfile::getEmail() {
	return m_email;
}
void PersonProfile::AddAttValPair(const AttValPair& attval) {
	string* result = m_attvals.search(attval.attribute);
	if (result == nullptr || result != &attval.value) {
		m_attvals.insert(attval.attribute, attval.value);
		m_attributes.push_back(attval.attribute);
		m_numPairs++;
	}
}

int PersonProfile::GetNumAttValPairs() const {
	return m_numPairs;
}

bool PersonProfile::getAttVal(int attribute_num, AttValPair& attval) const {
	string* result = m_attvals.search(m_attributes[attribute_num]);
	if (result != nullptr) {
		attval = AttValPair(m_attributes[attribute_num], *result);
		return true;
	}

	return false;
}