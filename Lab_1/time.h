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
	cout << "SET - Average filling time - " << size << " numbers: " << result << endl;
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
	cout << "VECTOR - Average filling time - " << size << " numbers: " << result << endl;
}

void average_finding_set(size_t size) {
	double result = 0.0;
	Set data;
	std::mt19937 gen(42);
	std::uniform_int_distribution<> distrib(-2000000, 2000000);
	for (size_t i = 0; i < size; i++)
	{
		data.insert(distrib(gen));
	}
	for (size_t i = 0; i < 1000; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		data.contains(distrib(gen));
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "SET - Average finding time - " << size << "numbers: " << result << endl;
}

void average_finding_vector(size_t size) {
	double result = 0.0;
	vector<int> data;
	std::mt19937 gen(42);
	std::uniform_int_distribution<> distrib(-2000000, 2000000);
	for (size_t i = 0; i < size; i++)
	{
		data.push_back(distrib(gen));
	}
	for (size_t i = 0; i < 1000; i++)
	{
		auto start = std::chrono::high_resolution_clock::now();
		std::find(data.begin(), data.end(), distrib(gen));
		auto end = std::chrono::high_resolution_clock::now();
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "VECTOR - Average finding time - " << size << " numbers: " << result << endl;
}

void average_erasing_set(size_t size) {
	double result = 0.0;
	std::mt19937 gen(42);
	std::uniform_int_distribution<> distrib(-2000000, 2000000);
	Set data;
	for (size_t i = 0; i < size; i++)
	{
		data.insert(distrib(gen));
	}
	for (size_t i = 0; i < 1000; i++)
	{
		bool deleted = false;
		int del = distrib(gen);
		auto start = std::chrono::high_resolution_clock::now();
		if (data.erase(del)) {
			deleted = true;
		}
		auto end = std::chrono::high_resolution_clock::now();
		if (deleted) {
			data.insert(del);
		}
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "SET - Average erasing time - " << size << " numbers: " << result << endl;
}

void average_erasing_vector(size_t size) {
	double result = 0.0;
	std::mt19937 gen(42);
	std::uniform_int_distribution<> distrib(-2000000, 2000000);
	vector<int> data;
	for (size_t i = 0; i < size; i++)
	{
		data.push_back(distrib(gen));
	}
	for (size_t i = 0; i < 1000; i++)
	{
		bool deleted = false;
		int del = distrib(gen);
		auto start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] == del) {
				data.erase(data.begin() + i);
				deleted = true;
				break;
			}
		}
		auto end = std::chrono::high_resolution_clock::now();
		if (deleted) {
			data.push_back(del);
		}
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "VECTOR - Average erasing time - " << size << " numbers: " << result << endl;
}

void average_insertion_set(size_t size) {
	double result = 0.0;
	std::mt19937 gen(42);
	std::uniform_int_distribution<> distrib(-2000000, 2000000);
	Set data;
	for (size_t i = 0; i < size; i++)
	{
		data.insert(distrib(gen));
	}
	for (size_t i = 0; i < 1000; i++)
	{
		bool inserted = false;
		int ins = distrib(gen);
		auto start = std::chrono::high_resolution_clock::now();
		if (data.insert(ins)) {
			inserted = true;
		}
		auto end = std::chrono::high_resolution_clock::now();
		if (inserted) {
			data.erase(ins);
		}
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "SET - Average insertion time - " << size << " numbers: " << result << endl;
}

void average_insertion_vector(size_t size) {
	double result = 0.0;
	std::mt19937 gen(42);
	std::uniform_int_distribution<> distrib(-2000000, 2000000);
	vector<int> data;
	for (size_t i = 0; i < size; i++)
	{
		data.push_back(distrib(gen));
	}
	for (size_t i = 0; i < 1000; i++)
	{
		int ins = distrib(gen);
		auto start = std::chrono::high_resolution_clock::now();
		data.push_back(ins);
		auto end = std::chrono::high_resolution_clock::now();
		data.erase(data.begin());
		double seconds = std::chrono::duration<double>(end - start).count();
		result += seconds / 1000;
	}
	cout << "VECTOR - Average insertion time - " << size << " numbers: " << result << endl;
}


