#pragma once
using namespace std;

class List
{
private:
	int* items;
	int itemCount;
	int size;

public:
	List();
	~List();

	void sortItem();
	int getItem(int index);
	void addItem(int itm);
	void insertItem(int index, int itm);
	int removeAt(int index);
	int removeItem(int itm);
	void printList();
	void Concat(List& list);
};