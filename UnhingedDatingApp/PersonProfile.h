#ifndef PERSONPROFILE
#define PERSONPROFILE

#include <string>
#include <vector>
#include "provided.h"
#include "RadixTree.h"

class PersonProfile {
public:
	PersonProfile(std::string name, std::string email);
	~PersonProfile();
	std::string GetName() const;
	std::string GetEmail() const;
	void AddAttValPair(const AttValPair& attval);
	int GetNumAttValPairs() const;
	bool GetAttVal(int attribute_num, AttValPair& attval) const;
private:
	RadixTree<std::vector<std::string>> m_attvals;
	std::vector<AttValPair> m_list;
	std::string m_name;
	std::string m_email;
	int m_numPairs;
};

#endif
