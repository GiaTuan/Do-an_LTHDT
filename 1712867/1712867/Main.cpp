#include <iostream>
#include <string>
#include "MyString.h"
#include <fstream>
using namespace std;

int main()
{
	MyString foo = "alpha";
	MyString bar = "beta";

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	system("pause");
	return 0;
}