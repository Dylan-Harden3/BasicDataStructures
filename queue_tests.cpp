#include <iostream>
#include "queue.h"

int main() {
  // make an empty queue
	Queue<int> queue;

	// enqueue 3 values into the queue
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	Queue<int> queue2 = queue;
	Queue<int> queue3(queue2);
	// remove the front element
	queue.dequeue();
	queue.print();
	queue2.print();
	queue3.print();
	// access the front element
	int value = queue.front();
	cout << value << endl;
	return 0;
}
