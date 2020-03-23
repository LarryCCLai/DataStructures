#ifndef HASHTABLE_H
#define HASHTABLE_H
#include"SinglyLinkedList.h"
enum HashMethod {
	Division,
	Multiplication
};

class HashTable {
private:
	SinglyLinkedList* keyLists;
	int M;
public:
	HashTable(int space);
	~HashTable();
	int Hash(int key);
	void Insert(int key);
	void Delete(int key);
	int Search(int key);

};
#endif // !HASHTABLE_H

