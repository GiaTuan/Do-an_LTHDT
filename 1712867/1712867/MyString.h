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
	MyString();
	MyString(const MyString &string);
	MyString(const MyString &string,int pos,int n_size);
	MyString(const char* string);
	MyString(const char* string,int n_size);
	MyString(int n_size, char c);
	MyString& operator=(const MyString &string);
	char operator[](int n)const;
	~MyString();
	int Size()const;
	friend istream& GetLine(istream &inDev, MyString &string);
	friend istream& operator>>(istream& inDev,  MyString &string);
	friend ostream& operator<<(ostream& outDev, const MyString &string);
};
#endif
