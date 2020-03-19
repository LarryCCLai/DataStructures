#ifndef SINGLYLINEDLIST_NODE_H
#define SINGLYLINEDLIST_NODE_H
class SinglyLinkedListNode {
private:
	int key;
	SinglyLinkedListNode* next;
public:
	SinglyLinkedListNode();
	SinglyLinkedListNode(int key);

	~SinglyLinkedListNode();

	int GetKey();
	SinglyLinkedListNode* GetNext();
	void SetKey(int key);
	void SetNext(SinglyLinkedListNode* next);

};

#endif // !SINGLYLINEDLISTNODE_H
