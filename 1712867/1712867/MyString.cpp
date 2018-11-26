#include "MyString.h"



const char& MyString::operator[](int n)const
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
	int n = string.Size();
	for (int i = 0; i < n; i++)
	{
		if (i == pos )
		{
			for (int j=i; count < n_size; j++)
			{
				this->str[count] = string[j];
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

void MyString::Clear()
{
	delete[] this->str;
}

MyString MyString::operator+(const MyString &string)
{
	MyString new_string;
	int size_1 = this->Size();
	int size_2 = string.Size();
	int new_size = size_1 + size_2;
	new_string = new char[new_size + 1];
	int i = 0;
	for (i; i < size_1; i++)
	{
		new_string.str[i] = this->str[i];
	}
	int j = 0;
	for (j=0,i; i < new_size; i++,j++)
	{
		new_string.str[i] = string[j];
	}
	new_string.str[new_size] = '\0';
	return new_string;
}

MyString operator+(const char* string_1, const MyString &string_2)
{
	MyString new_string;
	int size_1 = strlen(string_1);
	int size_2 = string_2.Size();
	int new_size = size_1 + size_2;
	new_string = new char[new_size + 1];
	int i = 0;
	for (i; i < size_1; i++)
	{
		new_string.str[i] = string_1[i];
	}
	int j = 0;
	for (j = 0, i; i < new_size; i++, j++)
	{
		new_string.str[i] = string_2[j];
	}
	new_string.str[new_size] = '\0';
	return new_string;
}

MyString MyString::operator+(const char &ch)
{
	MyString new_string;
	int size_1 = this->Size();
	int size_2 = 1;
	int new_size = size_1 + size_2;
	new_string = new char[new_size + 1];
	int i = 0;
	for (i; i < size_1; i++)
	{
		new_string.str[i] = this->str[i];
	}
	int j = 0;
	for (j = 0, i; i < new_size; i++, j++)
	{
		new_string.str[i] = ch;
	}
	new_string.str[new_size] = '\0';
	return new_string;
}
MyString operator+(const char &ch, const MyString &string)
{
	MyString new_string;
	int size_1 = 1;
	int size_2 = string.Size();
	int new_size = size_1 + size_2;
	new_string = new char[new_size + 1];
	int i = 0;
	for (i; i < size_1; i++)
	{
		new_string.str[i] = ch;
	}
	int j = 0;
	for (j = 0, i; i < new_size; i++, j++)
	{
		new_string.str[i] = string[j];
	}
	new_string.str[new_size] = '\0';
	return new_string;
}

//========================RELATIONAL OPERATORS========================

bool MyString::operator==(const MyString &string) const
{
	if (strcmp(this->str, string.str) == 0)
	{
		return true;
	}
	return false;
}

bool operator==(const char* string_1, const MyString &string_2)
{
	if (strcmp(string_1, string_2.str) == 0)
	{
		return true;
	}
	return false;
}

bool MyString::operator!=(const MyString &string)const
{
	if (!(*this == string))
	{
		return true;
	}
	return false;
}
bool operator!=(const char* string_1, const MyString &string_2) 
{
	if (!(string_1 ==string_2))
	{
		return true;
	}
	return false;
}

bool MyString::operator>(const MyString &string)const
{
	if (strcmp(this->str, string.str) > 0)
	{
		return true;
	}
	return false;
}

bool operator>(const char* string_1, const MyString &string_2)
{
	if (strcmp(string_1, string_2.str) > 0)
	{
		return true;
	}
	return false;
}

bool MyString::operator<(const MyString &string)const
{
	if (strcmp(this->str, string.str) <0)
	{
		return true;
	}
	return false;
}
bool operator<(const char* string_1, const MyString &string_2)
{
	if (strcmp(string_1, string_2.str) < 0)
	{
		return true;
	}
	return false;
}
bool MyString::operator>=(const MyString &string)const
{
	if ((*this == string) || (*this > string))
	{
		return true;
	}
	return false;
}
bool operator>=(const char* string_1, const MyString &string_2)
{
	if ((string_1 > string_2) || (string_1 == string_2))
	{
		return true;
	}
	return false;
}
bool MyString::operator<=(const MyString &string)const
{
	if ((*this == string) || (*this < string))
	{
		return true;
	}
	return false;
}
bool operator<=(const char* string_1, const MyString &string_2)
{
	if ((string_1 < string_2) || (string_1 == string_2))
	{
		return true;
	}
	return false;
}

//========================APPEND========================
MyString& MyString::Append(const MyString &string)
{
	MyString temp_string;
	int size_1 = this->Size();
	int size_2 = string.Size();
	int temp_size=size_1+size_2;
	temp_string.str = new char[temp_size+1];
	temp_string = *this + string;
	*this = temp_string;
	return *this;
}
MyString& MyString::Append(const MyString &string, int pos, int len)
{
	MyString temp_string;
	int size_1 = this->Size();
	int temp_size = size_1 + len;
	int count = 0;
	temp_string.str = new char[temp_size + 1];
	int n = string.Size();
	for (int i = 0; i < n; i++)
	{
		if (i == pos )
		{
			for (int j = i; count < len; j++)
			{
				temp_string.str[count] = string[j];
				count++;
			}
			temp_string.str[count] = '\0';
			temp_string = *this + temp_string;
			*this = temp_string;
			return *this;
		}
	}
}
MyString& MyString::Append(const char* string, int n_size)
{
	MyString temp_string;
	int size_1 = this->Size();
	int temp_size = size_1 + n_size;
	temp_string.str = new char[temp_size + 1];
	for (int i = 0; i < n_size; i++)
	{
		temp_string.str[i] = string[i];
	}
	temp_string.str[n_size] = '\0';
	temp_string = *this + temp_string;
	*this = temp_string;
	return *this;
}
MyString& MyString::Append(int n_size, const char &ch)
{
	MyString temp_string;
	int size_1 = this->Size();
	int temp_size = size_1 + n_size;
	temp_string.str = new char[temp_size + 1];
	for (int i = 0; i < n_size; i++)
	{
		temp_string.str[i] =ch;
	}
	temp_string.str[n_size] = '\0';
	temp_string = *this + temp_string;
	*this = temp_string;
	return *this;
}
//========================ASSIGN========================
MyString& MyString::Assign(const MyString &string)
{
	*this = string;
	return *this;
}

MyString& MyString::Assign(const MyString &string, int pos, int len)
{
	MyString temp_string;
	int count = 0;
	temp_string.str = new char[len + 1];
	int n = string.Size();
	for (int i = 0; i < n; i++)
	{
		if (i == pos)
		{
			for (int j = i; count < len; j++)
			{
				temp_string.str[count] = string[j];
				count++;
			}
			temp_string.str[count] = '\0';
			*this = temp_string;
			return *this;
		}
	}
}
MyString& MyString::Assign(const char* string, int n_size)
{
	MyString temp_string;
	temp_string.str = new char[n_size + 1];
	for (int i = 0; i < n_size; i++)
	{
		temp_string.str[i] = string[i];
	}
	temp_string.str[n_size] = '\0';
	*this = temp_string;
	return *this;
}
MyString& MyString::Assign(int n_size, const char &ch)
{
	MyString temp_string;
	temp_string.str = new char[n_size + 1];
	for (int i = 0; i < n_size; i++)
	{
		temp_string.str[i] = ch;
	}
	temp_string.str[n_size] = '\0';
	*this = temp_string;
	return *this;
}

//========================AT========================
char& MyString::At(int n)
{
	return this->str[n];
}
const char& MyString::At(int n)const
{
	return this->str[n];
}
//========================BACK========================
char& MyString::Back()
{
	return this->str[this->Size() - 1];
}
const char& MyString::Back() const
{
	return this->str[this->Size()-1];

}
//========================COMPARE========================

int MyString::Compare(const MyString& string) const
{
	if ( *this == string)
	{
		return 0;
	}
	else if (*this > string)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int MyString::Compare(int pos, int len, const MyString &string)const
{
	MyString str(*this, pos, len);
	return str.Compare(str);
}
int MyString::Compare(int pos, int len, const MyString &string, int subpos, int sublen)const
{
	MyString str_1(*this, pos, len);
	MyString str_2(string, subpos, sublen);
	return str_1.Compare(str_2);
}
int MyString::Compare(const char* s) const
{
	MyString str(s);
	return this->Compare(str);
}
int MyString::Compare(int pos, int len, const char* s) const
{
	MyString str_1(*this,pos,len);
	return str_1.Compare(s);
}
int MyString::Compare(int pos, int len, const char* s, int n) const
{
	MyString str(s, n);
	return this->Compare(pos, len, str);
}
//========================COPY========================

int MyString::Copy(char* string, int len, int pos)const
{
	int n = this->Size();
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == pos)
		{
			for (int j = i; count < len; j++)
			{
				string[count]=this->str[j];
				count++;
			}
			return count;
		}
	}
}


//========================SWAP========================
void Swap(MyString &string_1,MyString &string_2)
{
	MyString temp = string_1;
	string_1 = string_2;
	string_2 = temp;
}
	

//
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