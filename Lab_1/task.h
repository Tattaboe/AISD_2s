#include "tree.h"
#include <vector>

std::vector<int> task_vector(std::vector<int> v) {
    Set set;
    Set duplicates;
    std::vector<int> result;

    for (int num : v) {
        if (set.contains(num)) {
            duplicates.insert(num);
        }
        else {
            set.insert(num);
        }
    }

    for (int num : v) {
        if (duplicates.contains(num)) {
            result.push_back(num);
        }
    }

    return result;
}
