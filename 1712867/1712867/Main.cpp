#include <iostream>
#include <string>
#include "MyString.h"
using namespace std;

int main()
{
	MyString content;
MyString line;
cout << "Please introduce a text. Enter an empty line to finish:\n";
do {
	GetLine(std::cin, line);
	content = content + line;
	content=content +'\n';
} while (!line.Empty());
std::cout << "The text you introduced was:\n" << content;

	
	system("pause");
	return 0;
}