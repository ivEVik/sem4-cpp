#include <iostream>
#include <conio.h>

#include "task.h"


int main()
{
	int x = 0;
	
	std::cout << "x = ";
	std::cin >> x;
	std::cout << std::endl;
	
	for(int t = 0; t < 10; ++t)
		std::cout << x << '^' << t << " = " << power(x, t) << '\n';
	
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
