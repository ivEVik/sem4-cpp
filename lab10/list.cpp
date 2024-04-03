#include <iostream>

#include "list.h"
#include "bus.h"


template<class T> Node<T>::Node(const T val)
{
	this->val = val;
	this->pnext = nullptr;
}

template<class T> Node<T>::Node(const T val, Node<T>* const pnext)
{
	this->val = val;
	this->pnext = pnext;
}


template<class T> void Node<T>::setVal(const T val) { this->val = val; } 
template<class T> T Node<T>::getVal() const { return val; }

template<class T> void Node<T>::setNext(Node<T>* const pnext) { this->pnext = pnext; }
template<class T> Node<T>* Node<T>::getNext() const { return pnext; }



template<class T> List<T>::List()
{
	this->pfirst = nullptr;
	this->length = 0;
}

template<class T> List<T>::List(const T val)
{
	this->pfirst = new Node<T>(val);
	this->length = 1;
}

template<class T> List<T>::~List()
{
	Node<T>* node = pfirst;
	
	while(node)
	{
		Node<T>* prevNode = node;
		node = node->getNext();
		delete prevNode;
	}
}

template<class T> bool List<T>::contains(const T val) const
{
	Node<T>* node = pfirst;
	
	while(node)
	{
		if(node->getVal() == val)
			return true;
		node = node->getNext();
	}
	
	return false;
}

template<class T> T List<T>::get(const T key) const
{
	return findNode(key, false)->getVal();
}

template<class T> void List<T>::add(const T val)
{
	pfirst = new Node<T>(val, pfirst);
}

template<class T> bool List<T>::remove(const T val)
{
	if(!pfirst)
		return false;
	
	Node<T>* prevNode = findNode(val, true);
	
	if(prevNode)
	{
		Node<T>* node = prevNode->getNext();
		prevNode->setNext(node->getNext());
		delete node;
		return true;
	}
	
	if(pfirst->getVal() != val)
		return false;
	
	prevNode = pfirst;
	pfirst = pfirst->getNext();
	
	delete prevNode;
	return true;
}

template<> void List<Bus>::print() const
{
	Node<Bus>* node = pfirst;
	
	std::cout << "\n";
	
	while(node)
	{
		std::cout << '\t' << node->getVal().toString() << '\n';
		node = node->getNext();
	}
	
	std::cout << std::endl;
}

template<class T> void List<T>::print() const
{
	return;
}

template<class T> Node<T>* List<T>::findNode(const T val, const bool prev) const
{
	Node<T>* presult = pfirst;
	Node<T>* prevNode = nullptr;
	
	while(presult)
	{
		if(presult->getVal() == val)
			break;
		
		if(prev)
			prevNode = presult;
		
		presult = presult->getNext();
	}
	
	return prev ? prevNode : presult;
}


template class Node<Bus>;
template class List<Bus>;
