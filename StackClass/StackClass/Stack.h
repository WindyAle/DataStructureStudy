#pragma once
using namespace std;

template<typename T>
class Stack {
private:
	T* stack;
	int top;
	int size;

public:
	Stack(int stacksize);
	~Stack();
	bool empty();
	T& tops();
	void push(const T& item);
	void pop();
	void print();
};

