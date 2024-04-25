#include "tree.h"
#include <random>
#include <chrono>

using namespace std;
using std::cout, std::endl, std::vector;

void average_filling_set(size_t size) {
	double result = 0.0;
	for (size_t i = 0; i < 100; i++)
	{
		std::mt19937 gen(i);
		std::uniform_int_distribution<> distrib(-2000000, 2000000);
		Set data;
		auto start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < size; i++)
		{
			data.insert(distrib(gen));
		}
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 100;
		//cout << i + 1 << " try: " << seconds << " seconds" << endl;
	}
	cout << "SET - Average filling - " << size << " numbers: " << result << endl;
}

void average_filling_vector(size_t size) {
	double result = 0.0;
	for (size_t i = 0; i < 100; i++)
	{
		std::mt19937 gen(i);
		std::uniform_int_distribution<> distrib(-2000000, 2000000);
		vector<int> data;
		auto start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < size; i++)
		{
			data.push_back(distrib(gen));
		}
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 100;
		//cout << i + 1 << " try: " << seconds << " seconds" << endl;
	}
	cout << "VECTOR - Average filling -" << size << " numbers: " << result << endl;
}


int main() {

	average_filling_set(1000);
	average_filling_set(10000);
	average_filling_set(100000);

	average_filling_vector(1000);
	average_filling_vector(10000);
	average_filling_vector(100000);

	
}