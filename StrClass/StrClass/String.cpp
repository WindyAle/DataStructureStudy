#include "String.h"

String::String() : String(10) {

}

String::String(int m) {
	size = m;
	buffer = new char[m];
	length = 0;
}

String::String(String& s) : String(s.length + 1) {
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	buffer[length] = '\0';
	length = s.length;
}

String::String(char* init, int m) : String(m + 1) {
	for (int i = 0; i < m; i++)
		buffer[i] = init[i];
	buffer[m] = '\0';
	length = m;
}

String::~String() {
	delete[] buffer;
}

String String::Concat(String t) {
	String result(length + t.length + 1);

	for (int i = 0; i < length; i++)
		result.buffer[i] = buffer[i];
	for (int j = 0; j < t.length; j++)
		result.buffer[length + j] = t.buffer[j];

	result.buffer[length + t.length] = '\0';
	result.length = length + t.length;

	return result;
}

String& String::operator=(const String& s) {
	delete[] buffer;
	buffer = new char[s.length + 1];
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	buffer[length] = '\0';
	length = s.length;

	return *this;
}

void String::print() {
	for (int i = 0; i < length; i++)
		cout << buffer[i];
	cout << endl;
}

int String::Length() {
	return length;
}