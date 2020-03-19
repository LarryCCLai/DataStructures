#include<iostream>
#include"Queue.h"
using namespace std;

int main() {
	Queue* queue = new Queue();
	queue->Push(1);
	queue->Push(2);
	queue->Push(3);
	cout << queue->Front() << endl;
	queue->Pop();
	cout << queue->Front() << endl;
	cout << queue->Back() << endl;
	cout << queue->Size() << endl;

	system("pause");
	return 0;

}