#ifndef SINGLYLINEDLIST_NODE_H
#define SINGLYLINEDLIST_NODE_H
class SinglyLinkedListNode {
private:
	int data;
	SinglyLinkedListNode* next;
public:
	SinglyLinkedListNode();
	SinglyLinkedListNode(int key);

	~SinglyLinkedListNode();

	int GetData();
	SinglyLinkedListNode* GetNext();
	void SetData(int key);
	void SetNext(SinglyLinkedListNode* next);

};

#endif // !SINGLYLINEDLISTNODE_H
