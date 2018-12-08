#ifndef __MYSTRING_H___
#define __MYSTRING_H___
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "Iterator.h"
using namespace std;
class MyString
{
private:
	char* str;
public:
	static const size_t npos = -1;
	// CONSTRUCTOR
	MyString();
	MyString(const MyString &string);
	MyString(const MyString &string, size_t pos, size_t n_size);
	MyString(const char* string);
	MyString(const char* string, size_t n_size);
	MyString(size_t n_size, char c);
	// DESTRUCTOR
	~MyString();
	// OPERATOR[]
	char& operator[] (size_t pos);
	const char& operator[](size_t pos)const;
	// OPERATOR=
	MyString& operator=(const MyString &string);
	MyString& operator= (const char* s);
	MyString& operator= (char c);
	// OPERATOR+
	friend MyString operator+(const MyString &string_1, const MyString &string_2);
	friend MyString operator+(const MyString &string_1, const char* string_2);
	friend MyString operator+(const char* string_1, const MyString &string_2);
	friend MyString operator+(const MyString &string, const char &ch);
	friend MyString operator+(const char &ch, const MyString &string);
	// RELATIONAL OPERATORS
	bool operator==(const MyString &string)const;
	friend bool operator==(const char* string_1, const MyString &string_2);
	bool operator==(const char* &string)const;
	bool operator!=(const MyString &string)const;
	friend bool operator!=(const char* string_1, const MyString &string_2);
	bool operator!=(const char* &string)const;
	bool operator>(const MyString &string)const;
	friend bool operator>(const char* string_1, const MyString &string_2);
	bool operator>(const char* &string)const;
	bool operator<(const MyString &string)const;
	friend bool operator<(const char* string_1, const MyString &string_2);
	bool operator<(const char* &string)const;
	bool operator>=(const MyString &string)const;
	friend bool operator>=(const char* string_1, const MyString &string_2);
	bool operator>=(const char* &string)const;
	bool operator<=(const MyString &string)const;
	friend bool operator<=(const char* string_1, const MyString &string_2);
	bool operator<=(const char* &string)const;

	// OTHERs FUNCTIONS
	void Len(size_t &pos, size_t &len, Iterator first, Iterator last, const MyString &string);
	MyString createSubString(Iterator first, Iterator last);
	void findPos(size_t &pos, Iterator p, const MyString &string);
	// APPEND
	MyString& Append(const MyString &string);
	MyString& Append(const MyString &string, size_t pos, size_t len);
	MyString& Append(const char* string);
	MyString& Append(const char* string, size_t n_size);
	MyString& Append(size_t n_size, const char &ch);
	MyString& Append(Iterator first, Iterator last); //iterator
	// ASSIGN
	MyString& Assign(const MyString &string);
	MyString& Assign(const MyString &string, int pos, int len);
	MyString& Assign(const char* string);
	MyString& Assign(const char* string, int n_size);
	MyString& Assign(int n_size, const char &ch);
	MyString& Assign(Iterator first, Iterator last); //iterator
	// AT
	char& At(int pos);
	const char& At(int pos)const;
	// BACK
	char& Back();
	const char& Back() const;
	// BEGIN
	Iterator Begin();
	// END
	Iterator End();
	// CBEGIN
	const Iterator Cbegin();
	// CEND
	const Iterator Cend();
	// RBEGIN
	ReverseIterator Rbegin();
	// REND
	ReverseIterator Rend();
	// RCBEGIN
	const ReverseIterator Crbegin();
	// RCEND
	const ReverseIterator Crend();
	// CAPACITY
	int Capacity() const;
	// CLEAR
	void Clear();
	// COMPARE
	int Compare(const MyString& str) const;
	int Compare(size_t pos, size_t len, const MyString &string)const;
	int Compare(size_t pos, size_t len, const MyString &string, size_t subpos, size_t sublen)const;
	int Compare(const char* s) const;
	int Compare(size_t pos, size_t len, const char* s) const;
	int Compare(size_t pos, size_t len, const char* s, size_t n) const;
	// COPY
	size_t Copy(char* string, size_t len, size_t pos=0)const;
	// C_STR
	const char* C_str() const;
	// DATA
	const char* Data() const;
	// EMPTY
	bool Empty() const;
	// ERASE
	MyString& Erase(size_t pos = 0, size_t len = npos);
	MyString& Erase(Iterator first);
	MyString& Erase(Iterator first, Iterator last);
	// FIND
	size_t Find(const MyString& str, size_t pos = 0) const;
	size_t Find(const char* s, size_t pos = 0) const;
	size_t Find(const char* s, size_t pos, size_t n) const;
	size_t Find(char c, size_t pos = 0) const;
	// FIND_FIRST_NOT_OF
	size_t Find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t Find_first_not_of(const char* s, size_t pos = 0) const;
	size_t Find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t Find_first_not_of(char c, size_t pos = 0) const;
	// FIND_FIRST_OF
	size_t Find_first_of(const MyString& str, size_t pos = 0) const;
	size_t Find_first_of(const char* s, size_t pos = 0) const;
	size_t Find_first_of(const char* s, size_t pos, size_t n) const;
	size_t Find_first_of(char c, size_t pos = 0) const;
	// FIND_LAST_NOT_OF
	size_t Find_last_not_of(const MyString& str, size_t pos = 0) const;
	size_t Find_last_not_of(const char* s, size_t pos = 0) const;
	size_t Find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t Find_last_not_of(char c, size_t pos = 0) const;
	// FIND_LAST_OF
	size_t Find_last_of(const MyString& str, size_t pos = 0) const;
	size_t Find_last_of(const char* s, size_t pos = 0) const;
	size_t Find_last_of(const char* s, size_t pos, size_t n) const;
	size_t Find_last_of(char c, size_t pos = 0) const;
	// FRONT
	char& Front();
	const char& Front() const;
	// INSERT
	MyString& Insert(size_t pos, const MyString& str);
	MyString& Insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& Insert(size_t pos, const char* s);
	MyString& Insert(size_t pos, const char* s, size_t n);
	MyString& Insert(size_t pos, size_t n, char c);
	void Insert(Iterator p, size_t n, char c);
	Iterator Insert(Iterator p, char c);
	void Insert(Iterator p, Iterator first, Iterator last);
	// LENGTH
	size_t Length() const;
	// OPERTOR +=
	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);
	// POP_BACK
	void Pop_back();
	//PUSH_BACK
	void Push_back(char c);
	// REPLACE	
	MyString& Replace(size_t pos, size_t len, const MyString& str);
	MyString& Replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);
	MyString& Replace(size_t pos, size_t len, const char* s);
	MyString& Replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& Replace(size_t pos, size_t len, size_t n, char c);
	MyString& Replace(Iterator i1, Iterator i2, const MyString& str);
	MyString& Replace(Iterator i1, Iterator i2, const char* s);
	MyString& Replace(Iterator i1, Iterator i2, const char* s, size_t n);
	MyString& Replace(Iterator i1, Iterator i2, size_t n, char c);
	MyString& Replace(Iterator i1, Iterator i2, Iterator first, Iterator last);
	// RESIZE
	void Resize(size_t n);
	void Resize(size_t n, char c);
	// RFIND
	size_t Rfind(const MyString& str, size_t pos = npos) const;
	size_t Rfind(const char* s, size_t pos = npos) const;
	size_t Rfind(const char* s, size_t pos, size_t n) const;
	size_t Rfind(char c, size_t pos = npos) const;
	// SUBSTR
	MyString Substr(size_t pos = 0, size_t len = npos) const;
	// SWAP
	friend void Swap(MyString &string_1, MyString &string_2);
	// GETLINE
	friend istream& Getline(istream &inDev, MyString &string);
	friend istream& Getline(istream& inDev, MyString& string, char delim);
	// OPERATOR>>
	friend istream& operator>>(istream& inDev, MyString &string);
	// OPERTOR <<
	friend ostream& operator<<(ostream& outDev, const MyString &string);
	// SIZE
	size_t Size()const;
};
#endif
