#include <iostream>
#include <string>
#include "MyString.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	MyString a;
	in.open("test.txt", ios::in);
	if (in)
	{
		while (!in.eof())
		{
			a.Push_back(in.get());
		}
		in.close();
	}
	cout << a;
	system("pause");
	return 0;
}