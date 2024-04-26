
#include <vector>
#include "../include/tree.h" 

std::vector<int> findDuplicates(const std::vector<int>& v) {
    Set set;
    std::vector<int> duplicates;

    for (int num : v) {
        if (!set.insert(num)) { 
            duplicates.push_back(num); 
        }
    }

    return duplicates;
}