#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	char buffer[20];
	MyString str("Test string...");
	int length = str.Copy(buffer, 6, 5);
	buffer[length] = '\0';
	std::cout << "buffer contains: " << buffer << '\n';
	system("pause");
	return 0;
}