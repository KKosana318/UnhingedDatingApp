#ifndef MEMBERDATABASE
#define MEMBERDATABASE

#include <string>
#include <vector>
#include "provided.h"
#include "RadixTree.h"

class PersonProfile;

class MemberDatabase {
public:
	MemberDatabase();
	~MemberDatabase();
	bool LoadDatabase(std::string filename);
	std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
	const PersonProfile* GetMemberByEmail(std::string email) const;
private:
	RadixTree<std::vector<std::string>> m_pairsToEmails;
	RadixTree<PersonProfile*> m_emailsToPersons;
};

#endif