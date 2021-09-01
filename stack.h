#ifndef STACK_H
#define STACK_H
#include "array_list.h"
#include <cstddef> 
#include <iostream>
using namespace std;
template <typename Object>
class Stack {
	//size variable and arraylist to store the stack
   public:
   size_t size;
   ArrayList<Object> stack;
   //constructor
   Stack(): size(0), stack(ArrayList<Object>()){
   }
   //copy constructor
  Stack(const Stack& in ): size(in.stack.size()), stack(ArrayList<Object>(in.stack.capacity_())){
	   for(size_t i=0;i<size;i++){
		   stack.insert(i,in.stack[i]);
	   }
   }
   //destructor (arraylist destructor takes care of this)
   ~Stack(){
   }
   //copy assignment operator
  Stack& operator=(const Stack& rhs){
	   if(this != &rhs){
		   size = rhs.stack.size();
		   for(size_t i=0;i<size;i++){
			   stack.insert(i,rhs.stack[i]);
		   }
	   }
	   return *this;
   }
   //push and pop functions
   void push(const Object& in){
	   stack.insert(size,in);
	   size++;
   }
   void pop(){
	   if(size == 0){
		   throw std::out_of_range("out of range");
	   }
	   stack.remove(size-1);
	   size--;
   }
   //get the item on top of the stack
   Object& top(){
	   return stack[size-1];
   }
   //print the stack
   void print() {
	   cout << "Stack size: " << size << endl;
	   for(size_t i=0;i<size;i++){
		   cout << stack[i] << " ";
	   }
	   cout << endl;
   }
};

#endif  // STACK_H