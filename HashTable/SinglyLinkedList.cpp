#include"SinglyLinkedList.h"
#include<iostream>
SinglyLinkedList::SinglyLinkedList() {
	this->head = nullptr;
	this->size = 0;
}

SinglyLinkedList::~SinglyLinkedList() {

}

void SinglyLinkedList::Insert(int idx, int data) {
	if (idx > this->size) {
		std::cout << "[error] Insert: idx>length of the lineked list" << std::endl;
		return;
	}
	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
	SinglyLinkedListNode* cur = this->head;
	idx--;
	while (idx > 0) {
		cur = cur->GetNext();
	}
	newNode->SetNext(cur->GetNext());
	cur->SetNext(newNode);
	this->size++;
}

void SinglyLinkedList::Delete(int idx) {
	SinglyLinkedListNode* deletedNode;
	if (idx == 0) {
		deletedNode = this->head;
		this->head = this->head->GetNext();
	}
	else {
		SinglyLinkedListNode* cur = this->head;
		idx--;
		while (idx > 0) {
			cur = cur->GetNext();
		}
		deletedNode = cur->GetNext();
		cur->SetNext(deletedNode->GetNext());
	}
	delete deletedNode;
}

void SinglyLinkedList::PushFront(int data) {
	SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
	newNode->SetNext(this->head);
	this->head = newNode;
}

void SinglyLinkedList::PushBack(int data) {
	SinglyLinkedListNode* cur = head;
	while (cur->GetNext() != nullptr) {
		cur = cur->GetNext();
	}
	cur->SetNext(new SinglyLinkedListNode(data));
}

int SinglyLinkedList::Search(int data) {
	SinglyLinkedListNode* cur = this->head;
	while (cur != nullptr) {
		if (cur->GetData() == data) {
			return data;
		}
	}
	return NULL;
}
void SinglyLinkedList::Reverse() {
	SinglyLinkedListNode* prev = nullptr;
	SinglyLinkedListNode* cur = this->head;
	SinglyLinkedListNode* precede = cur->GetNext();
	while (precede!=nullptr) {
		cur->SetNext(prev);
		prev = cur;
		cur = precede;
		precede = precede->GetNext();
	}
	cur->SetNext(prev);
	this->head = cur;
}
