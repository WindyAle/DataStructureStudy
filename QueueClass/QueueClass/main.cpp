#include "Queue.h"
#include <iostream>

int main() {
	Queue<int> queue(5);

	for (int i = 0; i < 5; i++)
		queue.push(i);
	queue.print();

}