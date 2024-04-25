#include <vector>
#include <unordered_map>

std::vector<int> findDuplicates(const std::vector<int>& v) {
    std::unordered_map<int, int> countMap;
    std::vector<int> duplicates;

    for (int num : v) {
        countMap[num]++;
    }

   
    for (const auto& pair : countMap) {
        if (pair.second > 1) {
            duplicates.push_back(pair.first);
        }
    }

    return duplicates;
}
