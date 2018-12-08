#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include <iostream>
using namespace std;

class Iterator {
protected:
	char* it;
public:
	Iterator();
	Iterator(char *x);
	Iterator& operator=(const Iterator &p);
	Iterator& operator=(char* str);
	bool operator!=(Iterator p);
	bool operator==(const char &p);
	void operator++();
	char operator*();
	Iterator operator+(int x);
	Iterator operator-(int x);
};

//
class ReverseIterator :Iterator {
public:
	ReverseIterator();
	ReverseIterator(char *x);
	ReverseIterator& operator=(const ReverseIterator &p);
	ReverseIterator& operator=(char* str);

	bool operator!=(ReverseIterator p);
	bool operator==(const char &p);
	void operator++();
	char operator*();
	ReverseIterator operator+(int x);
	ReverseIterator operator-(int x);
};
#endif