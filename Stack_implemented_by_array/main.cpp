#include<iostream>
#include"Stack.h"
using namespace std;
int main() {
	Stack* stack = new Stack();
	stack->Push(0);
	stack->Push(1);
	std::cout << stack->Empty() << endl;
	std::cout << stack->Top() << endl;
	stack->Pop();
	std::cout << stack->Top() << endl;
	std::cout << stack->Size() << endl;
	system("pause");
	return 0;
}