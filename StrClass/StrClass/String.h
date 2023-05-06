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
	
	bool operator==(String t); // ���� ����
	bool operator!(); // ���� ����
	int Length(); // ���ڼ�
	String Substr(int i, int j); // i j ������ ��Ʈ��
	int Find(String pat); // ���� ã��
	void print();
};

