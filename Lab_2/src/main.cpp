#include "../include/hash_table.h"

int main() {
	std::cout << "Insert check" << std::endl;
	HashTable<int, int> hasht(10);

	hasht.insert(1, 3);
	hasht.insert(2, 11);
	hasht.insert(3, -1);
	hasht.insert(3, 8);
	hasht.insert(4, 6);
	hasht.insert(8, -7);
	hasht.insert(5, 2);
	hasht.insert(7, 3);
	hasht.insert(7, 19);
	hasht.insert(6, 10);
	
    hasht.print();
	
	
	std::cout << std::endl;
	std::cout << "count 7: ";
	std::cout << hasht.count(7) << std::endl;
	std::cout << "contains 3: ";
	std::cout << hasht.contains(3) << std::endl;
    std::cout << "erase 6: ";
	std::cout << hasht.erase(6);

	std::cout << std::endl;
	std::cout << std::endl;
	hasht.print();
	return 0;
}