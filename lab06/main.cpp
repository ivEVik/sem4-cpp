#include <functional>
#include <iostream>
#include <conio.h>

#include "Stroka.h"


int main()
{
	Stroka str = Stroka();
	
	str.vvod();
	std::cout << "\n";
	
	str.vyvod();
	
	char text[] = "thisisateststring";
	std::cout << "\n\nstr + \"" << text << "\" = ";
	Stroka str2 = Stroka(text);
	str = str + str2;
	str.vyvod();
	
	
	_getch();
}
