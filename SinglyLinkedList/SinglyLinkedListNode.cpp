#include"SinglyLinkedListNode.h"
#include<iostream>
SinglyLinkedListNode::SinglyLinkedListNode() {
	this->key = NULL;
	this->next = nullptr;
}
SinglyLinkedListNode::SinglyLinkedListNode(int key) {
	this->key = key;
	this->next = nullptr;
}
SinglyLinkedListNode::~SinglyLinkedListNode() {

}

int SinglyLinkedListNode::GetKey() {
	return this->key;
}

SinglyLinkedListNode* SinglyLinkedListNode::GetNext() {
	return this->next;
}
void SinglyLinkedListNode::SetKey(int key) {
	this->key = key;
}

void SinglyLinkedListNode::SetNext(SinglyLinkedListNode* next) {
	this->next = next;
}