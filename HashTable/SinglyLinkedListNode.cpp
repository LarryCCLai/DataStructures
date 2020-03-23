#include"SinglyLinkedListNode.h"
#include<iostream>
SinglyLinkedListNode::SinglyLinkedListNode() {
	this->data = NULL;
	this->next = nullptr;
}
SinglyLinkedListNode::SinglyLinkedListNode(int key) {
	this->data = key;
	this->next = nullptr;
}
SinglyLinkedListNode::~SinglyLinkedListNode() {

}

int SinglyLinkedListNode::GetData() {
	return this->data;
}

SinglyLinkedListNode* SinglyLinkedListNode::GetNext() {
	return this->next;
}
void SinglyLinkedListNode::SetData(int key) {
	this->data = key;
}

void SinglyLinkedListNode::SetNext(SinglyLinkedListNode* next) {
	this->next = next;
}