#ifndef STACK_H
#define STACK_H
class Stack {
private:
	int topIdx;
	int size;
	int* datas;
	void DoubleSize();
public:
	Stack();
	~Stack();
	void Push(int data);
	void Pop();
	int Top();
	int Size();
	bool Empty();
};

#endif // !STACK_H
