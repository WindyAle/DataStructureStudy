#pragma once
#include<iostream>
using namespace std;

class String {
private:
	char* buffer;
	int length;
	int size; 

	String(int m);
	
public:
	String();
	String(char* init, int m);
	String(String&);
	~String();
	String Concat(String t); 
	String& operator=(const String&);
	
	bool operator==(String t); // 동일 여부
	bool operator!(); // 공백 여부
	int Length(); // 문자수
	String Substr(int i, int j); // i j 사이의 스트링
	int Find(String pat); // 패턴 찾기
	void print();
};

