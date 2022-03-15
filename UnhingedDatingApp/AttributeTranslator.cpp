#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include "AttributeTranslator.h"

using namespace std;

AttributeTranslator::AttributeTranslator() {

}

AttributeTranslator::~AttributeTranslator() {

}

bool AttributeTranslator::Load(string filename) {
	ifstream translator(filename);
	if (!translator) {
		return false;
	}

	string line;
	while (getline(translator, line)) {
		bool first = true;
		for (int i = 0; i < line.size(); i++) {
			if (line.at(i) == ',' && first) { // only break at second comma
				first = false;
			}
			else if (line.at(i) == ',') {
				string key = line.substr(0, i);
				string value = line.substr(i + 1);
				int split = value.find(','); // used to turn value from string to AttValPair
				AttValPair second(value.substr(0, split), value.substr(split + 1));

				vector<AttValPair>* current = m_translator.search(key);

				if (current == nullptr) { // key doesnt exist
					m_translator.insert(key, { second });
				}
				else {
					bool add = true;
					for (int i = 0; i < current->size(); i++) {
						if ((*current)[i] == second) {
							add = false;
							break;
						}
					}
					if (add) {
						current->push_back(second);
					}
				}
				break;
			}
		}
	}

	return true;
}

vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs(const AttValPair& source) const {
	vector<AttValPair>* matches = m_translator.search(source.attribute + "," + source.value);
	if (matches == nullptr) {
		return {};
	}

	return *matches;
}