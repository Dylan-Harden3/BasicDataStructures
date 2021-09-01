#include <iostream>
#include "stack.h"
using namespace std;
int main() {
    // make an empty stack
	Stack<int> stack;

	// push 3 values onto the stack
	stack.push(1);
	stack.push(2);
	stack.push(3);
	Stack<int> stack2 = stack;
	Stack<int> stack3(stack2);
	// remove the top element
	stack.pop();
	stack.print();
	stack2.print();
	stack3.print();
	// access the top element
	int value = stack.top();
	cout << value << endl;
	return 0;
}
