#include "Stack.h"
#include <iostream>

template<typename T>
Stack<T>::Stack(int stacksize) {
	size = stacksize;
	if (size < 1) throw "������ ������� �ݵ�� 0���� Ŀ���մϴ�.";
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
	if (empty()) throw "stack�� ������ϴ�.";
		return stack[top];
}

template<typename T>
void Stack<T>::push(const T& item) {
	if (top == size - 1) throw "stack�� ���� á���ϴ�.";
	stack[++top] = item;
}

template<typename T>
void Stack<T>::pop() {
	if (empty()) throw "������ ����ֽ��ϴ�.";
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

	cout << "\nPop �Լ� ���� " << endl;
	stack.pop();
	stack.print();
	cout << "top : " << stack.tops() << endl;

	return 0;
}