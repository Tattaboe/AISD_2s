#pragma once
#include <iostream>
#include <utility>
#include <complex>


	struct Tree {
		int _data;
		Tree* _left, * _right;
		Tree(int data) : _data(data), _left(nullptr), _right(nullptr) {}
	};

	
	class Set {
	public:
		Set() : _root(nullptr) {}

		Set(const Set& rhs) : _root(nullptr) {
			copy_data(rhs.get_root());
		}

		Set& operator=(const Set& rhs) {
			Set copy(rhs);
			swap(copy);
			return *this;
		}

		bool insert(int key) {
			if (!_root) {
				_root = new Tree(key);
				return true;
			}
			if (contains(key)) return false;
			Tree* node = _root;
			bool left = false;
			while (node) {
				if (key < node->_data) {
					if (node->_left != nullptr) {
						node = node->_left;
						continue;
					}
					left = true;
					break;
				}
				else if (key > node->_data) {
					if (node->_right != nullptr) {
						node = node->_right;
						continue;
					}
					break;
				}
			}
			if (left) node->_left = new Tree(key);
			else node->_right = new Tree(key);
			return true;
		}

		bool contains(int key) {
			Tree* node = _root;
			while (node) {
				if (key < node->_data) node = node->_left;
				else if (key > node->_data) node = node->_right;
				else return true;
			}
			return false;
		}

		bool erase(int key) {
			bool deleted = false;
			_root = erase_node(_root, key, deleted);
			return deleted;
		}

		void print() {
			subprint(_root);
			std::cout << std::endl;
		}

		Tree*& get_root() {
			return _root;
		}

		Tree* get_root() const {
			return _root;
		}

		~Set() {
			delete_node(_root);
		}

	private:
		Tree* _root;

		void copy_data(Tree* node) {
			if (node != nullptr) {
				this->insert(node->_data);
				copy_data(node->_left);
				copy_data(node->_right);
			}
		}

		void swap(Set& rhs) noexcept {
			std::swap(_root, rhs.get_root());
		}

		Tree* erase_node(Tree* node, int key, bool& deleted) {
			if (node == nullptr) return node;
			if (key < node->_data) node->_left = erase_node(node->_left, key, deleted);
			else if (key > node->_data) node->_right = erase_node(node->_right, key, deleted);
			else {
				if (node->_left == nullptr) {
					Tree* temp = node->_right;
					delete node;
					deleted = true;
					return temp;
				}
				else if (node->_right == nullptr) {
					Tree* temp = node->_left;
					delete node;
					deleted = true;
					return temp;
				}
				Tree* temp = max_left(node->_left);
				node->_data = temp->_data;
				node->_left = erase_node(node->_left, temp->_data, deleted);
			}
			return node;
		}

		void subprint(Tree* node) {
			if (node != nullptr) {
				subprint(node->_left);
				std::cout << node->_data << ' ';
				subprint(node->_right);
			}
			return;
		}

		void delete_node(Tree* node) {
			if (node != nullptr) {
				delete_node(node->_left);
				delete_node(node->_right);
				delete node;
			}
		}



		Tree* max_left(Tree* node) {
			while (node->_right != nullptr) {
				node = node->_right;
			}
			return node;
		}
	};