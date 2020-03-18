#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
	int* datas;
	int idx;
	int size;
	void DoubleSize();
public:
	Queue ();
	~Queue ();

	bool Empty();
	int Front();
	int Back();
	void Push(int key);
	void Pop();
	int Size();
	
};

#endif // !QUEUE_H
