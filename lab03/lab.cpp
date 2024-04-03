#include <functional>
#include <iostream>
#include <conio.h>

#include "lab.h"


int main()
{
	int array[10];
	size_t length = sizeof(array) / sizeof(int);
	
	std::cout << "Array\t\t= ";
	initArray(array, length);
	printArray(array, length);
	
	std::cout << "\nBubble sort\t= ";
	bubbleSort(array, length, true);
	printArray(array, length);
	
	std::cout << "\n\nArray\t\t= ";
	initArray(array, length);
	printArray(array, length);
	
	std::cout << "\nQsort\t\t= ";
	quickSort(array, length, true);
	printArray(array, length);
	
	_getch();
}

void bubbleSort(int* array, const size_t length, const bool ascending)
{
	bubbleSortRange(array, 0, length, ascending);
}

void bubbleSortRange(int* array, const size_t rangeStart, const size_t rangeEnd, const bool ascending)
{
	std::function<bool(int, int)> compare = ascending
		? [](int a, int b) -> bool { return a < b; }
		: [](int a, int b) -> bool { return a > b; };
	
	bool cycle = true;
	while(cycle)
	{
		cycle = false;
		
		for(size_t t = rangeStart + 1; t < rangeEnd; ++t)
			if(compare(array[t], array[t - 1]))
			{
				int a = array[t];
				array[t] = array[t - 1];
				array[t - 1] = a;
				
				cycle = true;
			}
	}
}

void quickSort(int* array, const size_t length, const bool ascending)
{
	quickSortRange(array, 0, length, ascending);
}

void quickSortRange(int* array, const size_t rangeStart, const size_t rangeEnd, const bool ascending)
{
	if(rangeStart >= rangeEnd)
		return;
	
	std::function<bool(int, int)> compare = ascending
		? [](int a, int b) -> bool { return a < b; }
		: [](int a, int b) -> bool { return a > b; };
	
	size_t currentIndex = rangeStart;
	for(size_t t = rangeStart + 1; t < rangeEnd; ++t)
		if(compare(array[t], array[rangeStart]))
		{
			int a = array[t];
			array[t] = array[++currentIndex];
			array[currentIndex] = a;
		}
	
	int a = array[rangeStart];
	array[rangeStart] = array[currentIndex];
	array[currentIndex] = a;
	
	if(currentIndex > rangeStart)
		quickSortRange(array, rangeStart, currentIndex, ascending);
	
	if(currentIndex < rangeEnd)
		quickSortRange(array, currentIndex + 1, rangeEnd, ascending);
}


void printArray(const int* array, const size_t length)
{
	std::cout << "{ ";
	for(size_t t = 0; t < length; ++t)
		std::cout << array[t] << ' ';
	std::cout << '}';
}

void initArray(int* array, const size_t length)
{
	for(size_t t = 0; t < length; ++t)
		array[t] = rand();
}
