#pragma once
using namespace std;

template<typename T>
class Queue {
private:
	T* queue;
	int front, rear, capacity;

public:
	Queue(int);
	bool IsEmpty();
	T& Front();
	T& Rear();
	void push(T);
	void pop();
	void print();
};

