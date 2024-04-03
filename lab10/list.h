
#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <string>


template<class T>
struct Node
{
public:
	Node() = delete;
	Node(const T);
	Node(const T, Node* const);
	
	
	void setVal(const T); 
	T getVal() const;
	
	void setNext(Node* const);
	Node* getNext() const;
private:
	T val;
	Node* pnext = nullptr;
};


template<class T>
class List
{
public:
	List();
	List(const T);
	
	~List();
	
	
	bool contains(const T) const;
	
	T get(const T) const;
	
	void add(const T);
	
	bool remove(const T);
	
	void print() const;
private:
	Node<T>* pfirst;
	
	size_t length;
	
	
	Node<T>* findNode(const T, const bool) const;
};


#endif
