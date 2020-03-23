#ifndef SINGLYLINEDLIST_H
#define SINGLYLINEDLIST_H
#include"SinglyLinkedListNode.h"
class SinglyLinkedList {
private:
	SinglyLinkedListNode* head;
	int size;
public:
	SinglyLinkedList ();
	~SinglyLinkedList ();
	void Insert(int idx, int data);
	void Delete(int idx);
	void PushFront(int data);
	void PushBack(int data);
	int Search(int data);
	void Reverse();
	void Travel();
};

#endif // !SINGLYLINEDLIST_H

