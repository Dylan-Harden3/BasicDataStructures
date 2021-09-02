#ifndef QUEUE_H
#define QUEUE_H
#include "array_list.h"
#include <cstddef> 
#include <iostream>
template <typename Object>
class Queue {
//yo
	//size variable and arraylist to store the queue
	public:
	size_t size;
	ArrayList<Object> queue;
	//constructor
	Queue(): size(0),queue(ArrayList<Object>()){
	}
	//copy constructor
	Queue(const Queue& in): size(in.queue.size()), queue(ArrayList<Object>(in.queue.capacity_())){
		for(size_t i=0;i<size;i++){
			queue.insert(i,in.queue[i]);
		}
	}
	//destructor (arraylist destructor takes care of this)
	~Queue(){
	}
	//copy assignment operator
	Queue& operator=(const Queue& rhs){
		if(this != &rhs){
			size = rhs.queue.size();
			for(size_t i=0;i<size;i++){
			   queue.insert(i,rhs.queue[i]);
			}
		}
		return *this;
	}
	//enqueue and dequeue functions
	void enqueue(const Object& in){
		queue.insert(size,in);
		size++;
	}
	Object dequeue() {
		Object ans = queue[0];
		queue.remove(0);
		size--;
		return ans;
	}
	//function to get the item at the front of the queue
	Object& front(){
		return queue[0];
	}
	//print the queue
	void print(){
		cout << "Queue size: " << queue.size() << endl;
		for(size_t i=0;i<queue.size();i++){
			cout << queue[i] << " ";
		}
		cout << endl;
	}
};

#endif  // QUEUE_H
