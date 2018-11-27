#ifndef __MYSTRING_H___
#define __MYSTRING_H___
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <iterator>
using namespace std;

class MyString
{
private:
	char* str;
public:

	//CONSTRUCTOR
	MyString();
	MyString(const MyString &string);
	MyString(const MyString &string,int pos,int n_size);
	MyString(const char* string);
	MyString(const char* string,int n_size);
	MyString(int n_size, char c);
	
	//DESTRUCTOR
	~MyString();

	//OVERLOAD FUNCTIONS
	const char& operator[](int n)const;
	MyString& operator=(const MyString &string);

	//
	MyString operator+(const MyString &string);
	MyString operator+(const char* string);
	friend MyString operator+(const char* string_1,const MyString &string_2);
	MyString operator+(const char &ch);
	friend MyString operator+(const char &ch, const MyString &string);
	
	// RELATIONAL OPERATORS
	bool operator==(const MyString &string)const;
	friend bool operator==(const char* string_1, const MyString &string_2);
	bool operator!=(const MyString &string)const;
	friend bool operator!=(const char* string_1, const MyString &string_2);
	bool operator>(const MyString &string)const;
	friend bool operator>(const char* string_1, const MyString &string_2);
	bool operator<(const MyString &string)const;
	friend bool operator<(const char* string_1, const MyString &string_2);
	bool operator>=(const MyString &string)const;
	friend bool operator>=(const char* string_1, const MyString &string_2);
	bool operator<=(const MyString &string)const;
	friend bool operator<=(const char* string_1, const MyString &string_2);

	// APPEND
	MyString& Append(const MyString &string);
	MyString& Append(const MyString &string, int pos, int len);
	MyString& Append(const char* string, int n_size);
	MyString& Append(int n_size,const char &ch);

	// ASSIGN
	MyString& Assign(const MyString &string);
	MyString& Assign(const MyString &string, int pos, int len);
	MyString& Assign(const char* string, int n_size);
	MyString& Assign(int n_size, const char &ch);

	// AT
	char& At(int pos);
	const char& At(int pos)const;
	// BACK
	char& Back();
	const char& Back() const;
	// CAPACITY
	int Capacity() const;

	//COMPARE
	int Compare(const MyString& str) const;
	int Compare(int pos, int len, const MyString &string)const;
	int Compare(int pos, int len, const MyString &string,int subpos,int sublen)const;
	int Compare(const char* s) const;
	int Compare(int pos, int len, const char* s) const;
	int Compare(int pos, int len, const char* s, int n) const;

	//COPY
	int Copy(char* string, int len, int pos)const;

	// EMPTY
	bool Empty() const;
	// SWAP
	friend void Swap(MyString &string_1,MyString &string_2);



	//
	friend istream& GetLine(istream &inDev, MyString &string);
	friend istream& operator>>(istream& inDev,  MyString &string);
	friend ostream& operator<<(ostream& outDev, const MyString &string);

	//OTHERS
	int Size()const;
	void Clear();
};
#endif
