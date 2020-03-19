#include"DoublyLinkedListNode.h"
#include<iostream>
DoublyLinkedListNode::DoublyLinkedListNode() {
	this->data = NULL;
	this->next = nullptr;
	this->prev = nullptr;
}

DoublyLinkedListNode::DoublyLinkedListNode(int key) {
	this->data = key;
	this->next = nullptr;
	this->prev = nullptr;
}

DoublyLinkedListNode::~DoublyLinkedListNode() {
	this->next = nullptr;
	this->prev = nullptr;
}

int DoublyLinkedListNode::GetData() {
	return this->data;
}

DoublyLinkedListNode* DoublyLinkedListNode::GetNext() {
	return this->next;
}

DoublyLinkedListNode* DoublyLinkedListNode::GetPrev() {
	return this->prev;
}

void DoublyLinkedListNode::SetData(int data) {
	this->data = data;
}

void DoublyLinkedListNode::SetNext(DoublyLinkedListNode* next) {
	this->next = next;
}

void DoublyLinkedListNode::SetPrev(DoublyLinkedListNode* prev) {
	this->prev = prev;
}