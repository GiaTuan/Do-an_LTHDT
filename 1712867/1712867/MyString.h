#ifndef __MYSTRING_H___
#define __MYSTRING_H___
#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
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
	MyString(const MyString &string,size_t pos,size_t n_size);
	MyString(const char* string);
	MyString(const char* string,size_t n_size);
	MyString(size_t n_size, char c);
	
	// DESTRUCTOR
	~MyString();

	// OPERATOR[]
	char& operator[] (size_t pos);
	const char& operator[](size_t pos)const;

	// OPERATOR=
	MyString& operator=(const MyString &string);

	// OPERATOR+
	friend MyString operator+(const MyString &string_1, const MyString &string_2);
	friend MyString operator+(const MyString &string_1,const char* string_2);
	friend MyString operator+(const char* string_1,const MyString &string_2);
	friend MyString operator+(const MyString &string,const char &ch);
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
	// APPEND
	MyString& Append(const MyString &string);
	MyString& Append(const MyString &string, size_t pos, size_t len);
	MyString& Append(const char* string);
	MyString& Append(const char* string, size_t n_size);
	MyString& Append(size_t n_size,const char &ch);

	// ASSIGN
	MyString& Assign(const MyString &string);
	MyString& Assign(const MyString &string, int pos, int len);
	MyString& Assign(const char* string);
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

	// COMPARE
	int Compare(const MyString& str) const;
	int Compare(size_t pos, size_t len, const MyString &string)const;
	int Compare(size_t pos, size_t len, const MyString &string, size_t subpos, size_t sublen)const;
	int Compare(const char* s) const;
	int Compare(size_t pos, size_t len, const char* s) const;
	int Compare(size_t pos, size_t len, const char* s, size_t n) const;

	// COPY
	size_t Copy(char* string, size_t len, size_t pos)const;

	// C_STR
	const char* C_str() const;
	
	// DATA
	const char* Data() const;

	// ERASE
	MyString& Erase(size_t pos=0, size_t len=npos);
	
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

	// INSERT
	MyString& Insert(size_t pos, const MyString& str);
	MyString& Insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& Insert(size_t pos, const char* s);
	MyString& Insert(size_t pos, const char* s, size_t n);
	MyString& Insert(size_t pos, size_t n, char c);

	// FRONT
	char& Front();
	const char& Front() const;

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

	// EMPTY
	bool Empty() const;
	
	MyString& Replace(size_t pos, size_t len, const MyString& str);
	MyString& Replace(size_t pos, size_t len, const MyString& str,size_t subpos, size_t sublen);
	MyString& Replace(size_t pos, size_t len, const char* s);
	MyString& Replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& Replace(size_t pos, size_t len, size_t n, char c);

	// RESIZE
	void Resize(size_t n);
	void Resize(size_t n, char c);

	// SUBSTR
	MyString Substr(size_t pos = 0, size_t len = npos) const;

	// SWAP
	friend void Swap(MyString &string_1,MyString &string_2);

	// GETLINE
	friend istream& GetLine(istream &inDev, MyString &string);
	friend istream& Getline(istream& inDev, MyString& string, char delim);
	friend istream& operator>>(istream& inDev,  MyString &string);
	friend ostream& operator<<(ostream& outDev, const MyString &string);

	// SIZE
	size_t Size()const;

	// CLEAR
	void Clear();
};
#endif
