#include "../include/hash_table.h"
#include <random>

int main() {
    std::cout << "Insert check" << std::endl;
    HashTable<int, int> hasht(10);

    /* hasht.insert(1, 3);
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

    std::cout << std::endl;
    std::cout << "Search 5: ";
    auto search_result = hasht.search(5);
    if (search_result) {
        std::cout << search_result->value;
    }
    else {
        std::cout << "Element not found";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;*/

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 10);

    const int size = 50;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
        std::cout << arr[i] << " ";

        auto search_result = hasht.search(arr[i]);
        if (search_result) {
            hasht.insert_or_assign(arr[i], search_result->value + 1);
        }
        else {
            hasht.insert(arr[i], 1);
        }
    }

    std::cout << std::endl;
    hasht.print();

    return 0;
}
