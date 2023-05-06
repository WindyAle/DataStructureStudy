#include "OrderedList.h"
#include <iostream>
#include <algorithm>

List::List() {
	itemCount = 0;
	size = 5;
	items = new int[size];
}

List::~List() {
	delete[] items;
}

void List::sortItem() {
	for (int i = 0; i < itemCount - 1; i++)
		for (int j = i + 1; j < itemCount; j++)
			if (items[i] > items[j])
				swap(items[i], items[j]);
}

int List::getItem(int index) {
	if (index < itemCount)
		return items[index];
	else
		return -99999;
}

void List::addItem(int itm) {
	if (itemCount < size) {
		int pos;
		for (pos = 0; pos < itemCount; pos++)
			if (items[pos] > itm)
				break;
		if (pos == itemCount) {
			items[itemCount] = itm;
			itemCount++;
		}
		else
			insertItem(pos, itm);
	}
	else {
		int* newItems = new int[size * 2];

		for (int i = 0; i < itemCount; i++)
			newItems[i] = items[i];
		newItems[itemCount] = itm;
		itemCount++;

		delete[] items;
		items = newItems;
		size = size * 2;

		sortItem();
	}
}

void List::insertItem(int index, int itm) {
	for (int i = itemCount; index < i; i--)
		items[i] = items[i - 1];
	items[index] = itm;
	itemCount++;
}

int List::removeAt(int index) {
	int tmp = 0;

	if (index >= itemCount)
		return -99999;
	else
		tmp = items[index];

	for (int i = index; i < itemCount; i++)
		items[i] = items[i + 1];
	itemCount--;

	return tmp;
}

int List::removeItem(int itm) {
	int index = 0;

	for (int i = 0; i <= itemCount; i++)
		if (items[i] == itm) {
			index = i;
			break;
		}
		else if (i == itemCount)
			return -99999;

	for (int j = index; j < itemCount; j++)
		items[j] = items[j + 1];
	itemCount--;

	return index;
}

void List::Concat(List& list) {
	int* newItems = new int[size * 2];

	for (int i = 0; i < itemCount; i++)
		newItems[i] = items[i];
	delete[] items;
	items = newItems;
	size = size * 2;
	 
	for (int j = 0; j < list.itemCount; j++)
		addItem(list.items[j]);
}

void List::printList() {
	for (int i = 0; i < itemCount; i++) {
		if (i == itemCount - 1)
			cout << items[i] << endl;
		else
			cout << items[i] << " - ";
	}
}