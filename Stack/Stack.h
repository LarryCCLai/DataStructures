#ifndef STACK_H
#define STACK_H
template<class DataType>
class Stack {
private:
	int topIdx;
	int size;
	DataType* Datas;
	
public:
	Stack();
	~Stack();
	void push(DataType data);
	void pop();
	DataType top();
	int size();
	bool empty();
};

#endif // !STACK_H
