#ifndef LAB2_INCLUDE_HASHTABLE_H
#define LAB2_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>


template <typename K, typename V>
class HashTable {
    struct Pair {
        K key;
        V value;

    };

    std::vector<Pair> _data;
    size_t _size;

	size_t hash_func(const K& key) const {
		if constexpr (std::is_arithmetic_v<K>) {
			return key % capacity();
		}
		else {
			float hashedSum = 0;
			for (char character : static_cast<std::string>(key)) {
				hashedSum += static_cast<float>(character); // ASCII-код символа
			}
			return size_t(hashedSum) % capacity();
		}
	}

public:

    HashTable(size_t capacity) : _size(0), _data(capacity) {}

    HashTable(const HashTable& other) : _data(other._data), _size(other._size) {}

	HashTable& operator=(const HashTable& other) {
		if (this == &other)
			return *this;
		_data = other._data;
		_size = other._size;
	}

	~HashTable() {
		_data.clear();
		_size = 0;
	}

	size_t size() const {
		return _size;
	}

	size_t capacity() const {
		return _data.size();
	}

	void print() const {
		for (size_t i = 0; i < _data.size(); ++i) {
			std::cout << i << ": ";
			for (const auto& pair : _data[i]) {
				std::cout << "{" << pair.key << " : " << pair.value << "} ";
			}
			std::cout << std::endl;
		}
	}

	
};

#endif