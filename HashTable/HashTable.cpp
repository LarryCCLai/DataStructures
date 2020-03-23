#include"HashTable.h"
HashTable::HashTable(int space) {
	this->keyLists = new SinglyLinkedList[space];
	this->M = space;
}

HashTable::~HashTable() {
	delete[]this->keyLists;
}

int HashTable::Hash(int key) {
	return key % this->M;
}

void HashTable::Insert(int key) {
	int slot = this->Hash(key);
	this->keyLists[slot].PushBack(key);
}

void HashTable::Delete(int key) {
	int slot = this->Hash(key);
	this->keyLists[slot].Delete(key);
}

int HashTable::Search(int key) {
	int slot = this->Hash(key);
	return this->keyLists[slot].Search(key);
}