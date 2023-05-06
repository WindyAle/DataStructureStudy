#include "String.h"
#include <iostream>

int main() {
	String str1((char*)"hello", 5);
	String str2((char*)"world", 5);
	String str3;

	str1.print();
	str2.print();
	str3 = str1.Concat(str2);
	str3.print();

	cout << "Length: " << str3.Length() << endl;

	return 0;
}