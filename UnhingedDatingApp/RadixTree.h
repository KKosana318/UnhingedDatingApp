#ifndef RADIXTREE
#define RADIXTREE

#include <map>
#include <string>
#include "provided.h"

using namespace std;

template <typename ValueType>
class RadixTree {
public:
	RadixTree();
	~RadixTree();
	void insert(string key, const ValueType& value);
	ValueType* search(string key) const;
private:
	map<string, ValueType> m_tree;
};

template <typename ValueType>
RadixTree<ValueType>::RadixTree() {

}

template <typename ValueType>
RadixTree<ValueType>::~RadixTree() {

}

template <typename ValueType>
void RadixTree<ValueType>::insert(string key, const ValueType& value) {
	m_tree.insert(key, value);
}

template <typename ValueType>
ValueType* RadixTree<ValueType>::search(string key) const {
	map<string, ValueType>::iterator i = m_tree.begin();

	for (; i != m_tree.end(); i++) {
		if ((*i)->first == key) {
			return &((*i)->second);
		}
	}

	return nullptr;
}

#endif