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
	void Insert(int idx, int key);
	void Delete(int idx);
	int Search(int key);
};

#endif // !SINGLYLINEDLIST_H

