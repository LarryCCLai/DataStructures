#ifndef DoublyLinkedListNode_H
#define DoublyLinkedListNode_H

class DoublyLinkedListNode {
private:
	int data;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;
public:
	DoublyLinkedListNode();
	DoublyLinkedListNode(int key);
	~DoublyLinkedListNode();
	int GetData();
	DoublyLinkedListNode* GetNext();
	DoublyLinkedListNode* GetPrev();
	void SetData(int data);
	void SetNext(DoublyLinkedListNode* next);
	void SetPrev(DoublyLinkedListNode* prev);
};

#endif // !DoublyLinkedListNode_H
