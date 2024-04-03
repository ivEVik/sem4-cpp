#include <cstdio>
#include <conio.h>

#include "task.h"


int main()
{
	int array[] = { 100, 200, 300 };
	
	int *ptr1 = array;
	int *ptr2 = &array[2];
	
	PR(ptr1);
	ptr1++;
	PR(ptr1);
	PR(ptr2);
	++ptr2;
	
	printf("ptr2-ptr1=%u\n", ptr2-ptr1);
	
	_getch();
	return 0;
}

int power(const int x, const int n)
{
	int result = 1;
	
	for(int t = 0; t < n; ++t)
		result *= x;
	
	return result;
}
