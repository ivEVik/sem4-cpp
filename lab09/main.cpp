#include <iostream>
#include <conio.h>

#include "sort.h"


int main()
{
	int array[10];
	size_t length = sizeof(array) / sizeof(int);
	
	for(size_t t = 0; t < length; ++t)
	{
		array[t] = rand();
		std::cout << array[t] << ' ';
	}
	std::cout << std::endl;
	
	Sort(array, length);
	
	for(size_t t = 0; t < length; ++t)
		std::cout << array[t] << ' ';
	
	_getch();
	return 0;
}