
#ifndef STROKA_H
#define STROKA_H


class Stroka
{
public:
	Stroka();
	Stroka(const char*);
	Stroka(const Stroka&);
	Stroka(const size_t);
	~Stroka();
	
	
	size_t dlina() const;
	
	void vvod();
	void vyvod();
	
	
	Stroka& operator=(const Stroka&);
	Stroka& operator+(const Stroka&);
	bool operator==(const Stroka&) const;
	
	const char& operator[](const size_t) const;
	char& operator[](const size_t);
private:
	char* str;
	size_t len;
	
	void resize(const size_t, const bool);
};


#endif
