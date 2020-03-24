#include"DoublyLinkedList.h"
#include<iostream>
DoublyLinkedList::DoublyLinkedList() {
	this->head = nullptr;
	this->size = 0;
	this->tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
	while (this->head != nullptr) {
		DoublyLinkedListNode* tmp = this->head;
		this->head = this->head->GetNext();
		delete tmp;
	}
}

void DoublyLinkedList::Insert(int idx, int data) {
	if (idx == 0) {
		this->PushFront(data);
		return;
	}
	DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
	DoublyLinkedListNode* cur = this->head;
	idx--;
	while (idx-- > 0) {
		cur = cur->GetNext();
	}
	newNode->SetNext(cur->GetNext());
	newNode->SetPrev(cur);
	cur->GetNext()->SetPrev(newNode);
	cur->SetNext(newNode);
	this->size++;
}

void DoublyLinkedList::Delete(int idx) {
	DoublyLinkedListNode* deletedNode;
	if (idx == 0) {
		deletedNode = this->head;
		this->head = this->head->GetNext();
		this->head->SetPrev(nullptr);
	}
	else {
		DoublyLinkedListNode* cur = this->head;
		idx--;
		while (idx-- > 0) {
			cur = cur->GetNext();
		}
		deletedNode = cur->GetNext();
		cur->SetNext(deletedNode->GetNext());
		if (deletedNode->GetNext() != nullptr) {
			deletedNode->GetNext()->SetPrev(cur);
		}
		else {
			this->tail = cur;
		}
	}
	delete deletedNode;
}

void DoublyLinkedList::PushFront(int data) {
	DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
	newNode->SetNext(this->head);
	if (this->head == nullptr) {
		this->tail = newNode;
	}
	else{
		this->head->SetPrev(newNode);
	}
	this->head = newNode;
}

void DoublyLinkedList::PushBack(int data) {
	DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
	newNode->SetPrev(this->tail);
	if (this->tail == nullptr) {
		this->head = newNode;
	}
	else {
		this->tail->SetNext(newNode);
	}
	this->tail = newNode;
}

int DoublyLinkedList::Search(int data) {
	DoublyLinkedListNode* cur = this->head;
	while (cur != nullptr) {
		if (cur->GetData() == data) {
			return data;
		}
		cur = cur->GetNext();
	}
	return NULL;
}

void DoublyLinkedList::TravelFromHead() {
	DoublyLinkedListNode* cur = this->head;
	while (cur != nullptr) {
		std::cout << cur->GetData();
		cur = cur->GetNext();
	}
}
void DoublyLinkedList::TravelFromTail() {
	DoublyLinkedListNode* cur = this->tail;
	while (cur != nullptr) {
		std::cout << cur->GetData();
		cur = cur->GetPrev();
	}
}