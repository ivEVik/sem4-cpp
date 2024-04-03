#include <iostream>
#include <conio.h>

#include "task.h"


int main()
{
	int a = 2;
	int b = 5;
	
	std::cout << "before swapping:\ta = " << a << ", b = " << b << std::endl;
	
	//obmen1(a, b);
	//std::cout << "after swap 1:\t\ta = " << a << ", b = " << b << std::endl;
	
	obmen2(&a, &b);
	std::cout << "after swap 2:\t\ta = " << a << ", b = " << b << std::endl;
	
	obmen3(a, b);
	std::cout << "after swap 3:\t\ta = " << a << ", b = " << b << std::endl;
	
	_getch();
	return 0;
}

/*void obmen1(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}*/

void obmen2(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void obmen3(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
