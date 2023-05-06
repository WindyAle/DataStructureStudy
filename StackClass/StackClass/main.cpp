#include "Stack.h"
#include <iostream>

int main() {
	int n;

	cout << "Input stack size : ";
	cin >> n;
	Stack<int> stack(n);

	for (int i = 0; i < n; i++) {
		cout << "push : ";
		cin >> n;
		stack.push(n);
	}
	
	stack.print();
	cout << "top : " << stack.tops() << endl;
	
	return 0;
}