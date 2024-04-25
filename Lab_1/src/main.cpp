
#include "../include/tree.h"
#include "../include/task.h"
#include "../include/time.h"





int main()
{
    std::vector<int> test = {3, 2, 2, 4, 6, 1, 7, 6, 9};
    std::vector<int> res = findDuplicates(test);

    for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;

    return 0;

   /*average_filling_set(1000);
	average_filling_set(10000);
	average_filling_set(100000);

	average_filling_vector(1000);
	average_filling_vector(10000);
	average_filling_vector(100000);

	average_finding_set(1000);
	average_finding_set(10000);
	average_finding_set(100000);

	average_finding_vector(1000);
	average_finding_vector(10000);
	average_finding_vector(100000);

    average_erasing_set(1000);
	average_erasing_set(10000);
	average_erasing_set(100000);

	average_erasing_vector(1000);
	average_erasing_vector(10000);
	average_erasing_vector(100000);

	average_insertion_set(1000);
	average_insertion_set(10000);
	average_insertion_set(100000);

	average_insertion_vector(1000);
	average_insertion_vector(10000);
	average_insertion_vector(100000);*/

}