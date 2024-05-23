#ifndef LAB2_INCLUDE_HASHTABLE_H
#define LAB2_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>


template <typename K, typename V>
class HashTable {
	struct Pair {
		K key;
		V value;

		bool not_empty;

		Pair() : not_empty(true) {}
		Pair(const K& key, const V& value) : key(key), value(value), not_empty(false) {}

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
		for (const Pair& pair : _data) {
			if (!pair.not_empty)
				std::cout << "{" << pair.key << " : " << pair.value << "} ";
		}
		std::cout << std::endl;
	}

	bool insert(const K& key, const V& value) {
		size_t index = hash_func(key) % _data.size();
		size_t original_index = index;
		size_t first_empty_index = _data.size();

		while (!_data[index].not_empty) {
			if (_data[index].key == key) {
				return false;
			}
			if (_data[index].not_empty && first_empty_index == _data.size()) {
				first_empty_index = index;
			}
			index = (index + 1) % _data.size();
			if (index == original_index) {
				if (first_empty_index != _data.size()) {
					_data[first_empty_index] = Pair(key, value);
					_size++;
					return true;
				}
				else {
					return false;
				}
			}
		}
		_data[index] = Pair(key, value);
		_size++;
		return true;

	}

	bool insert_or_assign(const K& key, const V& value) {
		Pair* find_pair = search(key);
		if (find_pair) {
			find_pair->value = value;
			return false;
		}
		insert(key, value);
	}

	bool contains(const V& value) {
		for (Pair& pair : _data)
			if (pair.value == value && !pair.not_empty)
				return true;
		return false;
	}

	Pair* search(const K& key) {
		size_t start_index = hash_func(key) % _data.size();
		if ((_data[start_index].key == key) && (!_data[start_index].not_empty)) {
			return &_data[start_index];
		}
		size_t index = (start_index + 1) % _data.size();
		while (index != start_index) {
			if ((_data[index].key == key) && (!_data[index].not_empty)) {
				return &_data[index];
			}
			index = (index + 1) % _data.size();
		}
		return nullptr;
	}

	bool erase(const K& key) {
		Pair* find_pair = search(key);
		if (!find_pair)
			return false;
		find_pair->not_empty = true;
		return true;
	}

	size_t count(K key) {
		size_t index = hash_func(key) % _data.size();
		size_t cnt = 0;

		if (_data[index].not_empty) {
			return 0; 
		}

		size_t start_index = index;
		do {
			if (!_data[index].not_empty && _data[index].key == key) {
				cnt++;
			}
			index = (index + 1) % _data.size();
		} while (index != start_index);

		return cnt;
	}

	V operator[](const K& key) const {
		Pair* find_pair = search(key);
		if (find_pair)
			return find_pair->value;
		throw std::out_of_range("Key not found");
	}

	V& operator[](const K& key) {
		Pair* find_pair = search(key);
		if (find_pair)
			return find_pair->value;
		throw std::out_of_range("Key not found");
	}


};

#endif