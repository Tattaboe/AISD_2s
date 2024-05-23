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
	
	return 0;
}