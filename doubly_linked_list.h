#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
#include <iostream>
#include <cstddef>
using namespace std;
template <typename Object>
//node class
 class Node {
	public:
		//data, previous node and next node
		Object data;
		Node<Object>* next;
		Node<Object>* prev;
};

template <typename Object>
class DoublyLinkedList {
	//head
	public:
	Node<Object>* head;
	//constructor
	DoublyLinkedList(): head(nullptr) {}
	//destructor
	~DoublyLinkedList(){
		Node<Object>* cur = head;
		Node<Object>* nex = nullptr;
		//traverse the list freeing the memory 
		while(cur != nullptr){
			nex = cur->next;
			delete cur;
			cur = nex;
		}
	}
	//copy constructor
	DoublyLinkedList(const DoublyLinkedList& in) : head(nullptr){
		//set the head equal to the other list's head
		Node<Object>* temp = in.head;
		while(temp!=nullptr){
			//traverse the old list inserting the current data at the end of the new list
			insertatend(temp->data);
			temp=temp->next;
		}
	}
	//copy assignment operator
	DoublyLinkedList& operator=(const DoublyLinkedList& rhs){
		DoublyLinkedList<Object> temp(rhs);
		std::swap(temp.head,head);
		return *this;
	}
	//find the size of the list
	size_t size() {
		size_t c = 0;
		  Node<Object>* cur = head;
		while(cur != nullptr){
			//traverse until you reach a null node and increment the counter each time to find the size
			c++;
			cur = cur->next;
		}
		return c;
	}
	//[] operator
	Object& operator[](size_t index){
		if(index >= this->size()  ||  index <0){
			throw std::out_of_range("out of range");
		}
		Node<Object>* cur = head;
		for(size_t i=0;i<index;i++){
			cur = cur->next;
		}
		return cur->data;
	}
	//insert and remove functions
	void insert(size_t index, const Object& d){
		//check that the index is within range
		if(index > this->size()  ||  index <0){
			throw std::out_of_range("out of range");
		}
		//insert at the front
		if(index == 0){
			insertathead(d);
			return;
		}else if(index == this->size()){ //insert at the end
			insertatend(d);
			return;
		}else {
			Node<Object>* cur = head;
			//traverse until the desired position
			for(size_t i=0;i<index;i++){
				cur = cur->next;
			}
			//make a new node
			Node<Object>* n = new Node<Object>;
			//update the pointers for the current node and the new node
			n->data = d;
			n->next = cur;
			n->prev = cur->prev;
			cur->prev->next = n;
			cur->prev = n;
			return;
		}
	}
	void remove(size_t index){
		size_t c =0;
		if(index >= this->size()  ||  index <0){
			throw std::out_of_range("out of range");
		}
		if(index == 0){
			if(this->size() == 1){
				delete head;
				head = nullptr;
			}else{
				  Node<Object>* cur = head;
				head = head->next;
				head->prev = nullptr;
				delete cur;
			}
		}else if(index == this->size()-1){
			  Node<Object>* cur = head;
			while(cur->next != nullptr){
				cur = cur->next;
			}
			  Node<Object>* pre = cur->prev;
			pre->next = nullptr;
			delete cur;
		}else {
			Node<Object>* cur = head;
			while(c != index){
				cur = cur->next;
				c++;
			}
			Node<Object>* pre = cur->prev;
			Node<Object>* nex = cur->next;
			nex->prev = pre;
			pre->next = nex;
			delete cur;
		}
	}
	//function to show the data in the list
	void print() {
		Node<Object>* cur = head;
		cout << "Doublylinkedlist data" << endl;
		cout << "size = " << this->size() << endl;
		cout << "[ ";
		while(cur!= nullptr){
			cout << cur->data << ", ";
			cur = cur->next;
		}
		cout << "]" << endl;
	}
	//helper functions to insert at the begging and end of the list
	void insertathead(Object d) {
		Node<Object>* temp = new Node<Object>;
		temp->data = d;
		temp->prev = nullptr;
		temp->next = nullptr;
		if(head == nullptr){
			head = temp;
			return;
		}
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	void insertatend(Object d){
		Node<Object>* temp = new Node<Object>;
		temp->data = d;
		temp->prev = nullptr;
		temp->next = nullptr;
		if(head == nullptr){
			head = temp;
		}else {
			Node<Object>* cur = head;
			while(cur->next != nullptr){
				cur = cur->next;
			}
			cur->next = temp;
			temp->prev = cur;
		}
	}
};

#endif  // DOUBLY_LINKED_LIST_H
