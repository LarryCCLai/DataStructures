#include"Stack.h"

Stack::Stack() {
	this->datas = new int[1];
	this->topIdx = -1;
	this->size = 1;
}

Stack::~Stack() {
}

void Stack::DoubleSize() {
	this->size *= 2;
	int* tmp = this->datas;
	this->datas = new int[this->size];
	for (int i = 0; i <= topIdx; i++) {
		this->datas[i] = tmp[i];
	}
	delete[]tmp;
}

void Stack::Push(int key) {
	if (this->topIdx + 1 == this->size) {
		this->DoubleSize();
	}
	this->topIdx++;
	this->datas[this->topIdx] = key;
	
}

void Stack::Pop() {
	this->topIdx--;
}

bool Stack::Empty() {
	return this->topIdx == -1;
}

int Stack::Top() {
	return this->datas[this->topIdx];
}

int Stack::Size() {
	return this->topIdx + 1;
}




