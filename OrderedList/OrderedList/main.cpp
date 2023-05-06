#include "OrderedList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	List list;
	List list2;
	int addData = 0;
	int inData = 0;
	int inIndex = 0;

	for (int i = 0; i < 20; i++) {
		addData = rand() % 100 + 1;
		list.addItem(addData);
	}
	list.printList();

	cout << "\nAdd data : ";
	cin >> addData;
	list.addItem(addData);
	list.printList();

	cout << "\nGet data : ";
	cin >> inIndex;
	cout << list.getItem(inIndex - 1) << endl;

	cout << "\nRemove index : ";
	cin >> inIndex;
	cout << "Removed data : " << list.removeAt(inIndex - 1) << endl;

	cout << "\nRemove data : ";
	cin >> inData;
	cout << "Removed index : " << list.removeItem(inData) + 1 << endl;

	srand((unsigned int)time(NULL));

	cout << "\nNext is 2nd list" << endl;
	for (int i = 0; i < 20; i++) {
		addData = rand() % 100 + 1;
		list2.addItem(addData);
	}
	list2.printList();

	list.Concat(list2);
	cout << "\nConcat list" << endl;
	list.printList();

	return 0;
}