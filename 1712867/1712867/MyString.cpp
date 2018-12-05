#include "MyString.h"

char& MyString::operator[] (size_t pos)
{
	return this->str[pos];
}

const char& MyString::operator[](size_t pos)const
{
	return this->str[pos];
}
size_t MyString::Size()const
{
	return strlen(this->str);
}
MyString::MyString()
{
	size_t size = 0;
	this->str = new char[size+1];
	this->str[0] = '\0';
}
MyString::MyString(const MyString &string)
{
	size_t size = string.Size();
	this->str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		this->str[i] = string[i];
	}
	this->str[size] = '\0';
}
MyString::MyString(const MyString &string, size_t pos, size_t n_size)
{
	size_t size = n_size;
	size_t count = 0;
	this->str = new char[size + 1];
	size_t n = string.Size();
	for (size_t i = 0; i < n; i++)
	{
		if (i == pos )
		{
			for (size_t j=i; count < n_size; j++)
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
	size_t size = strlen(string);
	this->str = new char [size + 1];
	for (int i = 0; i < size; i++)
	{
		this->str[i] = string[i];
	}
	this->str[size] = '\0';
}
MyString::MyString(const char* string, size_t n_size)
{
	size_t size = n_size ;
	this->str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		this->str[i] = string[i];
	}
	this->str[size] = '\0';
}
MyString::MyString(size_t n_size, char c)
{
	size_t size = n_size ;
	this->str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		this->str[i] = c;
	}
	this->str[size] = '\0';
}
MyString& MyString::operator=(const MyString &string)
{
	delete[] this->str;
	size_t size = string.Size();
	this->str = new char[size+1];
	for (size_t i = 0; i < size; i++)
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

MyString operator+(const MyString &string_1, const MyString &string_2)
{
	MyString new_string;
	size_t size_1 = string_1.Size();
	size_t size_2 = string_2.Size();
	size_t new_size = size_1 + size_2;
	new_string.str = new char[new_size + 1];
	size_t i = 0;
	for (i; i < size_1; i++)
	{
		new_string.str[i] = string_1[i];
	}
	size_t j = 0;
	for (j=0,i; i < new_size; i++,j++)
	{
		new_string.str[i] = string_2[j];
	}
	new_string.str[new_size] = '\0';
	return new_string;
}
MyString operator+(const MyString &string_1,const char* string)
{
	MyString str(string);
	return string_1 + str;
}


MyString operator+(const char* string_1, const MyString &string_2)
{
	MyString str_1(string_1);
	return str_1 + string_2;
}

MyString operator+(const MyString &string,const char &ch)
{
	MyString str(1,ch);
	return string + str;
}
MyString operator+(const char &ch, const MyString &string)
{
	MyString str(1, ch);
	return str + string;
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
bool MyString::operator==(const char* &string)const
{
	if (strcmp(this->str, string) == 0)
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
	MyString str(string_1);
	return str != string_2;
}
bool MyString::operator!=(const char* &string)const

{
	MyString str(string);
	return *this != str;
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
	MyString str(string_1);
	return str > string_2;
}
bool MyString::operator>(const char* &string)const
{
	MyString str(string);
	return *this > str;
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
	MyString str(string_1);
	return str < string_2;
}
bool MyString::operator<(const char* &string)const
{
	MyString str(string);
	return *this < str;
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
	MyString str(string_1);
	return str >= string_2;
}
bool MyString::operator>=(const char* &string)const
{
	MyString str(string);
	return *this >= str;
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
	MyString str(string_1);
	return str <= string_2;
}
bool MyString::operator<=(const char* &string)const
{
	MyString str(string);
	return *this <= str;
}
//========================APPEND========================
MyString& MyString::Append(const MyString &string)
{
	MyString temp_string;
	size_t size_1 = this->Size();
	size_t size_2 = string.Size();
	size_t temp_size=size_1+size_2;
	temp_string.str = new char[temp_size+1];
	temp_string = *this + string;
	*this = temp_string;
	return *this;
}
MyString& MyString::Append(const MyString &string, size_t pos, size_t len)
{
	MyString str(string, pos, len);
	return this->Append(str);
}
MyString& MyString::Append(const char* string)
{
	MyString str(string);
	return this->Append(str);
}


MyString& MyString::Append(const char* string, size_t n_size)
{
	MyString str(string, 0, n_size);
	return this->Append(str);
}
MyString& MyString::Append(size_t n_size, const char &ch)
{
	MyString str(n_size, ch);
	return this->Append(str);

}
//========================ASSIGN========================
MyString& MyString::Assign(const MyString &string)
{
	*this = string;
	return *this;
}

MyString& MyString::Assign(const MyString &string, int pos, int len)
{
	MyString str(string, pos, len);
	return this->Assign(str);
}
MyString& MyString::Assign(const char* string)
{
	MyString str(string);
	return this->Assign(str);
}


MyString& MyString::Assign(const char* string, int n_size)
{
	MyString str(string, 0, n_size);
	return this->Assign(str);
}
MyString& MyString::Assign(int n_size, const char &ch)
{
	MyString str(n_size,ch);
	return this->Assign(str);
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
int MyString::Compare(size_t pos, size_t len, const MyString &string)const
{
	MyString str(*this, pos, len);
	return str.Compare(str);
}
int MyString::Compare(size_t pos, size_t len, const MyString &string, size_t subpos, size_t sublen)const
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
int MyString::Compare(size_t pos, size_t len, const char* s) const
{
	MyString str_1(*this,pos,len);
	return str_1.Compare(s);
}
int MyString::Compare(size_t pos, size_t len, const char* s, size_t n) const
{
	MyString str(s, n);
	return this->Compare(pos, len, str);
}
//========================COPY========================

size_t MyString::Copy(char* string, size_t len, size_t pos)const
{
	size_t n = this->Size();
	size_t count = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (i == pos)
		{
			for (size_t j = i; count < len; j++)
			{
				string[count]=this->str[j];
				count++;
			}
			return count;
		}
	}
}

//========================C_STR========================

const char* MyString::C_str()const
{
	size_t size = this->Size();
	char* cstr = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		cstr[i] = this->str[i];
	}
	cstr[size] = '\0';
	return cstr;
}

MyString& MyString::Erase(size_t pos, size_t len)
{
	try {
		if (pos > this->Size())
		{
			throw (char*)"out_of_range";
		}
		else
		{
			MyString str_1(*this, 0, pos);
			MyString str_2;
			if (len == -1)
			{
				str_2 = MyString();
			}
			else 
			{
				str_2=MyString(*this, pos + len, this->Size()); 
			}
			return *this= str_1 + str_2;
		}
	}
	catch (char* s)
	{
		if (strcmp(s, "out_of_range") == 0)
		{
			cout << "position is greater string length"<<endl;
		}
	}
}
//========================FIND========================

size_t MyString::Find(const MyString& str, size_t pos) const
{
	size_t size = this->Size();
	size_t subsize = str.Size();
	size_t x = MyString::npos;
	size_t j = 0;
	size_t k = 1;
	size_t n = subsize;
	for (size_t i = pos; i < size; i++)
	{
		if (this->str[i] == str[j])
		{
			x = i;
			for (j = i + 1;; j++)
			{
				if (n == 1)
				{
					return x;
				}
				else if (this->str[j] != str[k])
				{
					i = j;
					x = -1;
					j = 0;
					n = subsize;
					k = 1;
					break;
				}
				else
				{
					k++;
					n--;
				}
			}
			
		}
	}
}

size_t MyString::Find(const char* s, size_t pos ) const
{
	MyString str(s);
	return this->Find(str, pos);
}
size_t MyString::Find(const char* s, size_t pos, size_t n) const
{
	MyString str(s, n);
	return this->Find(str,pos);
}
size_t MyString::Find(char c, size_t pos ) const
{
	MyString str(1,c);
	return this->Find(str, pos);
}
//========================FIND_FIRST_NOT_OF========================
size_t MyString::Find_first_not_of(const MyString& string, size_t pos ) const
{
	size_t size_1 = this->Size();
	size_t size_2 = string.Size();
	bool flag = false;
	for (size_t i = pos; i < size_1; i++)
	{
		for (int j = 0; j < size_2; j++)
		{
			if (this->str[i] == string[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			return i;
		}
		flag = false;
	}
}
size_t MyString::Find_first_not_of(const char* s, size_t pos) const
{
	MyString str(s);
	return this->Find_first_not_of(str, pos);
	
}
size_t MyString::Find_first_not_of(const char* s, size_t pos, size_t n) const
{
	MyString str(s, n);
	return this->Find_first_not_of(str, pos);
}
size_t MyString::Find_first_not_of(char c, size_t pos ) const
{
	MyString str(1, c);
	return this->Find_first_not_of(str, pos);

}
//========================FIND_FIRST_OF========================
size_t MyString::Find_first_of(const MyString& string, size_t pos) const
{
	size_t size_1 = this->Size();
	size_t size_2 = string.Size();
	for (size_t i = pos; i < size_1; i++)
	{
		for (size_t j = 0; j < size_2; j++)
		{
			if (this->str[i] == string[j])
			{
				return i;
			}
		}
	}
	return -1;
}
size_t MyString::Find_first_of(const char* s, size_t pos) const
{
	MyString str(s);
	return this->Find_first_of(str, pos);

}
size_t MyString::Find_first_of(const char* s, size_t pos, size_t n) const
{
	MyString str(s, n);
	return this->Find_first_of(str, pos);
}
size_t MyString::Find_first_of(char c, size_t pos) const
{
	MyString str(1, c);
	return this->Find_first_of(str, pos);

}
//========================FIND_FIRST_NOT_OF========================
size_t Find_last(const MyString& string_1, const MyString& string_2, size_t pos, bool cond)
{
	size_t size_1 = string_1.Size();
	size_t size_2 = string_2.Size();
	bool *check = new bool[size_1];
	bool flag = false;
	for (size_t i = 0; i < size_1; i++)
	{
		for (size_t j = 0; j < size_2; j++)
		{
			if (string_1[i] == string_2[j])
			{
				check[i] = true;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			check[i] = false;
		}
		flag = false;
	}
	size_t x = -1;
	for (size_t i = size_1 - 1; i >= 0; i--)
	{
		if (cond == false)
		{
			if (check[i] == false)
			{
				x = i;
				break;
			}
		}
		else
		{
			if (check[i] == true)
			{
				x = i;
				break;
			}
		}
	}
	delete[] check;
	return x;
}

size_t MyString::Find_last_not_of(const MyString& str, size_t pos ) const
{
	return Find_last(*this, str, pos, false);
}
size_t MyString::Find_last_not_of(const char* s, size_t pos ) const
{
	MyString str(s);
	return this->Find_last_not_of(str, pos);
}
size_t MyString::Find_last_not_of(const char* s, size_t pos, size_t n) const
{
	MyString str(s,n);
	return this->Find_last_not_of(str, pos);
}
size_t MyString::Find_last_not_of(char c, size_t pos) const
{
	MyString str(1,c);
	return this->Find_last_not_of(str, pos);
}
//========================FIND_LAST_OF========================

size_t MyString::Find_last_of(const MyString& str, size_t pos ) const
{
	return Find_last(*this, str, pos, true);
}
size_t MyString::Find_last_of(const char* s, size_t pos) const
{
	MyString str(s);
	return this->Find_last_of(str, pos);
}
size_t MyString::Find_last_of(const char* s, size_t pos, size_t n) const
{
	MyString str(s,n);
	return this->Find_last_of(str, pos);
}
size_t MyString::Find_last_of(char c, size_t pos) const
{
	MyString str(1,c);
	return this->Find_last_of(str, pos);
}

MyString& MyString::Insert(size_t pos, const MyString& str)
{
	size_t n = this->Size();
	size_t m = str.Size();
	MyString temp_1(*this, 0, pos);
	MyString temp_2(*this,pos,n-pos);
	this->Clear();
	size_t newSize = n+m;
	this->str = new char[newSize + 1];
	size_t i = 0, k = 0, h=0;
	for (i; i < newSize; i++)
	{
		if (i < pos)
		{
			this->str[i] = temp_1[i];
		}
		else if (i>=pos && k<m)
		{
			this->str[i] = str[k];
			k++;
		}
		else
		{
			this->str[i] = temp_2[h];
			h++;
		}
	}
	this->str[i] = '\0';
	return *this;
}
MyString& MyString::Insert(size_t pos, const MyString& string, size_t subpos, size_t sublen)
{
	MyString str(string, subpos, sublen);
	return this->Insert(pos, str);
}

MyString& MyString::Insert(size_t pos, const char* s)
{
	MyString str(s);
	return this->Insert(pos, str);
}
MyString& MyString::Insert(size_t pos, const char* s, size_t n)
{
	MyString str(s,n);
	return this->Insert(pos, str);
}
MyString& MyString::Insert(size_t pos, size_t n, char c)
{
	MyString str(n,c);
	return this->Insert(pos, str);
}


//========================FRONT========================

char& MyString::Front()
{
	return this->str[0];
}
const char& MyString::Front() const
{
	return this->str[0];
}

//========================DATA========================

const char* MyString::Data() const
{
	return this->C_str();
}
//========================EMPTY========================
bool MyString::Empty() const
{
	if (this->Size() == 0)
	{
		return true;
	}
	return false;
}
//========================LENGTH========================

size_t MyString::Length() const
{
	return this->Size();
}

//========================OPERATOR += ========================

MyString& MyString::operator+= (const MyString& str)
{
	return *this = *this + str;
}
MyString& MyString::operator+= (const char* s)
{
	return *this = *this + s;
}
MyString& MyString::operator+= (char c)
{
	return *this = *this + c;
}
//========================POP_BACK========================

void MyString::Pop_back()
{
	this->Resize(this->Size() - 1);
}
//========================PUSH_BACK========================

void MyString::Push_back(char c)
{
	this->Resize(this->Size()+1, c);
}
//========================REPLACE========================

MyString& MyString::Replace(size_t pos, size_t len, const MyString& str)
{
	size_t n = this->Size();
	size_t m = str.Size();
	MyString temp(*this,pos+len,n);
	this->Resize(n + m-len);
	size_t newSize = this->Size();
	size_t j = 0;
	size_t i = pos;
	size_t k = 0;
	for (i ; i < newSize ; i++)
	{
		if (j<m)
		{
			this->str[i] = str[j];
			j++;
		}
		else
		{
			this->str[i] = temp[k];
			k++;
		}
	}
	return *this;
}
MyString& MyString::Replace(size_t pos, size_t len, const MyString& string, size_t subpos, size_t sublen)
{
	MyString str(string, subpos, sublen);
	return this->Replace(pos, len, str);
}
MyString& MyString::Replace(size_t pos, size_t len, const char* s)
{
	MyString str(s);
	return this->Replace(pos, len, str);
}
MyString& MyString::Replace(size_t pos, size_t len, const char* s, size_t n)
{
	MyString str(s, n);
	return this->Replace(pos, len, str);
}
MyString& MyString::Replace(size_t pos, size_t len, size_t n, char c)
{
	MyString str(n, c);
	return this->Replace(pos, len, str);
}
//========================RESIZE========================

void MyString::Resize(size_t n)
{
	MyString temp= *this;
	size_t size = this->Size();
	this->Clear();
	size_t NewSize = n + 1;
	this->str = new char[NewSize];
	size_t i = 0;
	for (i; i <n; i++)
	{
		if (i < size)
		{
			this->str[i] = temp[i];
		}
		else
		{
			this->str[i] = ' ';
		}
	}
	this->str[i] = '\0';
}
void MyString::Resize(size_t n, char c)
{
	MyString temp = *this;;
	size_t len = this->Size();
	this->Clear();
	this->str = new char[n+1];
	size_t i = 0;
	for (i; i < n; i++)
	{
		if (i < len)
		{
			this->str[i] = temp[i];
		}
		else
		{
			this->str[i] = c;
		}
	}
	this->str[i] = '\0';
}

//========================SUBSTR========================

MyString MyString::Substr(size_t pos, size_t len) const
{
	if (len == npos)
	{
		len = this->Size();
	}
	MyString string(*this,pos,len);
	return string;
}
//========================SWAP========================
void Swap(MyString &string_1,MyString &string_2)
{
	MyString temp = string_1;
	string_1 = string_2;
	string_2 = temp;
}
//========================GETLINE========================
istream& GetLine(istream &inDev, MyString &string)
{
	string.str= new char[255 + 1];
	inDev.getline(string.str, 255);
	return inDev;
}
istream& Getline(istream& inDev, MyString& string, char delim)
{
	string.str = new char[255 + 1];
	inDev.getline(string.str, 255, delim);
	return inDev;
}

//
istream& operator>>(istream& inDev, MyString &string)
{
	string.str = new char[255 + 1];
	inDev.getline(string.str, 255,' ');
	return inDev;
}
ostream& operator<<(ostream& outDev, const MyString &string)
{
	outDev << string.str;
	return outDev;
}