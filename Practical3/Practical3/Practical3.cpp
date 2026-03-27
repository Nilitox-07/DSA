#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include "Timer.h"

/*
	numbers.bin is a binary file that consists of some number of integer values.

	Read this file and store the numbers in a vector.

	There will be numbers in the vector that add up to a sum of 103149.

	Find these two values and print out the numbers, as well as what index each one is found at.
*/

void ReadNumberFileIntoVecAndSet(std::vector<int>& vec, std::unordered_set<int>& set);

void FindTwoNumbersThatSumUpTo(int num, std::vector<int>& vec, std::unordered_set<int>& set);

int main() {
	// Memory leak detection code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// This function call will set a breakpoint at the location of a leaked block
	// Set the parameter to the identifier for a leaked block
	_CrtSetBreakAlloc(-1);
	
	

	std::vector<int> vec;
	std::unordered_set<int> set;
	int findNumber = 5678;//103149;

	Timer timer;

	ReadNumberFileIntoVecAndSet(vec, set);

	timer.Start();

	FindTwoNumbersThatSumUpTo(findNumber, vec, set);

	timer.Stop();

	timer.Elapsed();

	std::cout << "\n\n";
	system("pause");
	return 0;
}

void ReadNumberFileIntoVecAndSet(std::vector<int>& vec, std::unordered_set<int>& set)
{
	std::ifstream file("numbers.bin", std::ios_base::binary);
	if (file.is_open())
	{
		int estSize;
		file.seekg(0, std::ios::end);
		estSize = file.tellg();
		file.seekg(0, std::ios::beg);
		int temp = 0;
		vec.reserve(estSize);
		while (!file.eof())
		{
			file.read((char*)&temp, sizeof(temp));
			if (file.eof())
				break;
			vec.push_back(temp);
			set.insert(temp);
		}
	}
}

void FindTwoNumbersThatSumUpTo(int num, std::vector<int>& vec, std::unordered_set<int>& set)
{
	int firstIndex = -1;
	int secondIndex = -1;
	int firstNumber = -1;
	int secondNumber = -1;
	for (int i = 0; i < vec.size(); ++i)
	{
		int otherNumber = abs(vec[i] - num);
		std::unordered_set<int>::iterator it = std::find(set.begin(), set.end(), otherNumber);
		if (it != set.end())
		{
			firstIndex = i;
			firstNumber = vec[i];
			secondNumber = *it;
			for (int j = i+1; j < vec.size(); ++j)
			{
				if (vec[j] == secondNumber)
				{
					secondIndex = j;
					break;
				}
			}
			break;
		}
	}
	// std::cout << "First Number: " << firstNumber << " at Index: " << firstIndex << "\nSecond Number: " << secondNumber << " at Index: " << secondIndex << "\n\n";
}
