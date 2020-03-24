#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H
#include"DoublyLinkedListNode.h"
class DoublyLinkedList{
private:
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;
	int size;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void Insert(int idx, int data);
	void Delete(int idx);
	void PushFront(int data);
	void PushBack(int data);
	int Search(int data);
	void TravelFromHead();
	void TravelFromTail();
};

#endif // !DoublyLinkedList_H

