#include "MyString.h"



char MyString::operator[](int n)const
{
	return this->str[n];
}
int MyString::Size()const
{
	return strlen(this->str);
}
MyString::MyString()
{
	int size = 1;
	this->str = new char[size+1];
	this->str[0] = '\0';
}
MyString::MyString(const MyString &string)
{
	int size = string.Size();
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = string[i];
	}
	this->str[size] = '\0';
}
MyString::MyString(const MyString &string, int pos, int n_size)
{
	int size = n_size;
	int count = 0;
	this->str = new char[size + 1];
	for (int i = 0; i < string.Size(); i++)
	{
		if (i == pos - 1)
		{
			for (int j=i; count < n_size; j++)
			{
				this->str[j] = string[j];
				count++;
			}
			this->str[size] = '\0';
			return;
		}
	}
}
MyString::MyString(const char* string)
{
	int size = strlen(string);
	this->str = new char [size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = string[i];
	}
	this->str[size] = '\0';
}
MyString::MyString(const char* string, int n_size)
{
	int size = n_size ;
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = string[i];
	}
	this->str[size] = '\0';
}
MyString::MyString(int n_size, char c)
{
	int size = n_size ;
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = c;
	}
	this->str[size] = '\0';
}
MyString& MyString::operator=(const MyString &string)
{
	delete[] this->str;
	int size = string.Size();
	this->str = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = string[i];
	}
	str[size] = '\0';
	return *this;
}
MyString::~MyString()
{
	delete[] this->str;
}
istream& GetLine(istream &inDev, MyString &string)
{
	string.str= new char[255 + 1];
	inDev.getline(string.str, 255);
	return inDev;
}
istream& operator>>(istream& inDev, MyString &string)
{
	string.str = new char[255 + 1];
	inDev.getline(string.str, 255);
	return inDev;
}
ostream& operator<<(ostream& outDev, const MyString &string)
{
	outDev << string.str;
	return outDev;
}