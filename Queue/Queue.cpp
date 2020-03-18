#include"Queue.h"

Queue::Queue() {
	this->datas = new int[1];
	this->idx = -1;
	this->size = 1;
}

Queue::~Queue() {
}

void Queue::DoubleSize() {
	this->size *= 2;
	int* tmp = this->datas;
	this->datas = new int[this->size];
	for (int i = 0; i <= idx; i++) {
		this->datas[i] = tmp[i];
	}
	delete[]tmp;
}

bool Queue::Empty() {
	return this->idx == -1;
}

int Queue::Front() {
	return this->datas[0];
}

int Queue::Back() {
	return this->datas[this->idx];
}

void Queue::Push(int key) {
	if (this->idx + 1 == this->size) {
		this->DoubleSize();
	}
	this->idx++;
	this->datas[this->idx] = key;
}

void Queue::Pop() {
	for (int i = 0; i < idx; i++) {
		this->datas[i] = this->datas[i + 1];
	}
	this->idx--;
}

int Queue::Size() {
	return this->idx + 1;
}
