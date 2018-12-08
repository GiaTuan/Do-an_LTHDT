#include "Iterator.h"

Iterator::Iterator()
{
	this->it = NULL;
}

Iterator::Iterator(char *x)
{
	this->it = x;
}

Iterator& Iterator::operator=(const Iterator &p)
{
	this->it = p.it;
	return *this;
}
Iterator& Iterator::operator=(char* str)
{
	this->it = str;
	return *this;
}
bool Iterator::operator!=(Iterator p)
{
	if (this->it != (p.it))
	{
		return true;
	}
	return false;
}

bool Iterator::operator==(const char &p)
{
	if (this->it == &p)
	{
		return true;
	}
	return false;
}

void Iterator::operator++()
{
	++it;
}
char Iterator::operator*()
{
	return *it;
}
Iterator Iterator::operator+(int x)
{
	Iterator p;
	p.it = this->it + x;
	return p;
}
Iterator Iterator::operator-(int x)
{
	Iterator p;
	p.it = this->it - x;
	return p;
}
//  REVERSE ITERATOR
ReverseIterator::ReverseIterator()
{
	this->it = NULL;
}
ReverseIterator::ReverseIterator(char *x)
{
	this->it = x;
}
ReverseIterator& ReverseIterator::operator=(const ReverseIterator &p)
{
	this->it = p.it;
	return *this;
}
ReverseIterator& ReverseIterator::operator=(char* str)
{
	this->it = str;
	return *this;
}

bool ReverseIterator::operator!=(ReverseIterator p)
{
	if (this->it != (p.it))
	{
		return true;
	}
	return false;
}
bool ReverseIterator::operator==(const char &p)
{
	if (this->it == &p)
	{
		return true;
	}
	return false;
}
void ReverseIterator::operator++()
{
	--it;
}
char ReverseIterator::operator*()
{
	return *it;
}
ReverseIterator ReverseIterator::operator+(int x)
{
	ReverseIterator p;
	p.it = this->it + x;
	return p;
}
ReverseIterator ReverseIterator::operator-(int x)
{
	ReverseIterator p;
	p.it = this->it - x;
	return p;
}