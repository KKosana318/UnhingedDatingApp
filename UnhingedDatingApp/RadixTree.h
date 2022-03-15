#ifndef RADIXTREE
#define RADIXTREE

#include <map>
#include <string>
#include <iostream>

template <typename ValueType>
class RadixTree {
public:
	RadixTree();
	~RadixTree();
	void insert(std::string key, const ValueType& value);
	ValueType* search(std::string key) const;
	void print();
private:
	std::map<std::string, ValueType> m_tree;
};

template <typename ValueType>
RadixTree<ValueType>::RadixTree() {

}

template <typename ValueType>
RadixTree<ValueType>::~RadixTree() {

}

template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value) {
	m_tree.insert({ key, value });
}

template <typename ValueType>
ValueType* RadixTree<ValueType>::search(std::string key) const {
	if (m_tree.find(key) != m_tree.end()) {
		return (ValueType*)&(m_tree.find(key)->second);
	}

	return nullptr; 
}

template <typename ValueType>
void RadixTree<ValueType>::print() {
	int counter = 0;
	for (typename std::map<std::string, ValueType>::iterator i = m_tree.begin(); i != m_tree.end(); i++) {
		if (counter++ > 30) {
			return;
		}
		std::cout << (i->first) << std::endl;
	}
}
#endif