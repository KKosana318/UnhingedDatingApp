#ifndef PERSONPROFILE
#define PERSONPROFILE

#include <string>
#include <vector>
#include "provided.h"

using namespace std;

class AttributeTranslator {
public:
	AttributeTranslator();
	~AttributeTranslator();
	bool Load(string filename);
	vector<AttValPair> FindCompatibleAttValPair(const AttValPair& source) const;

};

#endif