#include "Stack.h"
#include <iostream>

template<typename T>
Stack<T>::Stack(int stacksize) {
	size = stacksize;
	if (size < 1) throw "스택의 사이즈는 반드시 0보다 커야합니다.";
	stack = new T[size];
	top = -1;
}

template<typename T>
Stack<T>::~Stack() {
	delete[] stack;
}

template<typename T>
bool Stack<T>::empty() { return top == -1; }

template<typename T>
T& Stack<T>::tops() {
	if (empty()) throw "stack이 비었습니다.";
		return stack[top];
}

template<typename T>
void Stack<T>::push(const T& item) {
	if (top == size - 1) throw "stack이 가득 찼습니다.";
	stack[++top] = item;
}

template<typename T>
void Stack<T>::pop() {
	if (empty()) throw "스택이 비어있습니다.";
	size--;
	stack[top--];
}

template<typename T>
void Stack<T>::print() {
	for (int i = 0; i < size; i++)
		cout << stack[i] << " ";
	cout << endl;
}

int main() {
	int size;
	int n;

	cout << "Input stack size : ";
	cin >> size;
	Stack<int> stack(size);

	for (int i = 0; i < size; i++) {
		cout << "push : ";
		cin >> n;
		stack.push(n);
	}

	stack.print();
	cout << "top : " << stack.tops() << endl;

	cout << "\nPop 함수 실행 " << endl;
	stack.pop();
	stack.print();
	cout << "top : " << stack.tops() << endl;

	return 0;
}