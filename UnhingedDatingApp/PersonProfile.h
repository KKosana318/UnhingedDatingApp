#ifndef PERSONPROFILE
#define PERSONPROFILE

#include <string>
#include <vector>
#include "provided.h"
#include "RadixTree.h"

using namespace std;

class PersonProfile {
public:
	PersonProfile(string name, string email);
	~PersonProfile();
	string getName();
	string getEmail();
	void AddAttValPair(const AttValPair& attval);
	int GetNumAttValPairs() const;
	bool getAttVal(int attribute_num, AttValPair& attval) const;
private:
	string m_name;
	string m_email;
	int m_numPairs;
	RadixTree<string> m_attvals;
	vector<string> m_attributes;
};


#endif