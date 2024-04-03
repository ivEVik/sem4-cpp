#include <cstring>
#include <iostream>

#include "Stroka.h"


Stroka::Stroka()
{
	len = 0;
	str = new char[len];
}

Stroka::Stroka(const char* string)
{
	len = strlen(string);
	str = new char[len];
	
	for(size_t t = 0; t < len; ++t)
		str[t] = string[t];
}

Stroka::Stroka(const Stroka& string)
{
	len = string.len;
	str = new char[len];
	
	for(size_t t = 0; t < len; ++t)
		str[t] = string[t];
}

Stroka::Stroka(const size_t length)
{
	len = length;
	str = new char[len];
}

Stroka::~Stroka()
{
	delete[] str;
}


size_t Stroka::dlina() const
{
	return len;
}

void Stroka::vvod()
{
	std::cin >> str;
	len = strlen(str);
}

void Stroka::vyvod()
{
	for(size_t t = 0; t < len; ++t)
		std::cout << str[t];
}


Stroka& Stroka::operator=(const Stroka& other)
{
	if(this == &other)
		return *this;
	
	if(len != other.len)
		resize(other.len, false);
	
	for(size_t t = 0; t < len; ++t)
		str[t] = other[t];
	
	return *this;
}

Stroka& Stroka::operator+(const Stroka& other)
{
	size_t oldLen = len;
	resize(len + other.len, true);
	
	for(size_t t = oldLen; t < len; ++t)
		str[t] = other[t - oldLen];
	
	return *this;
}

bool Stroka::operator==(const Stroka& other) const
{
	if(this == &other)
		return true;
	
	if(len != other.len)
		return false;
	
	for(size_t t = 0; t < len; ++t)
		if(str[t] != other[t])
			return false;
	
	return true;
}

const char& Stroka::operator[](const size_t index) const
{
	return str[index];
}

char& Stroka::operator[](const size_t index)
{
	return str[index];
}


void Stroka::resize(const size_t length, const bool keepValues)
{
	char* oldStr = str;
	size_t shortLen = len < length ? len : length;
	
	len = length;
	str = new char[len];
	
	if(!keepValues)
	{
		delete[] oldStr;
		return;
	}
	
	for(size_t t = 0; t < shortLen; ++t)
		str[t] = oldStr[t];
	
	delete[] oldStr;
}
