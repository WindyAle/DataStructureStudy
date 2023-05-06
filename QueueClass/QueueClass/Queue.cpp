#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
Queue<T>::Queue(int Capacity) : capacity(Capacity) {
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

template<typename T>
bool Queue<T>::IsEmpty() { return front == rear; }

template<typename T>
T& Queue<T>::Front() {
	if (IsEmpty()) throw "Queue is empty.";
	return queue[(front + 1) % capacity];
}

template<typename T>
T& Queue<T>::Rear() {
	if (IsEmpty()) throw "Queue is empty.";
	return queue[rear-1];
}

template<typename T>
void Queue<T>::push(T item) {
	queue[rear] = item;
	rear = (rear + 1) % capacity;
}

template<typename T>
void Queue<T>::pop() {
	if (IsEmpty()) throw "Queue is empty.";
	front = (front + 1) % capacity;
	rear--;
}

template<typename T>
void Queue<T>::print() {
	for (int i = 0; i < rear; i++)
		cout << queue[i] << " ";
}

int main() {
	int capacity = 0;
	int n = 0;
	cout << "Capacity: ";
	cin >> capacity;
	Queue<int> queue(capacity + 1);

	srand((unsigned int) time(NULL));

	for (int i = 0; i < capacity; i++) {
		queue.push(rand() % 100 + 1);
	}
	queue.print();
	cout << "\nFront: " << queue.Front() << endl;
	cout << "Rear: " << queue.Rear() << endl;

	cout << "\npop 함수 시행" << endl;
	queue.pop();
	queue.print();
	cout << "\nFront: " << queue.Front() << endl;
	cout << "Rear: " << queue.Rear() << endl;

	return 0;
}