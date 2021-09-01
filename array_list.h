#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <cstddef> 
#include <iostream>
using namespace std;
template <typename Object>
class ArrayList {

	private :
	//size, capacity, and array
	size_t size_;
	size_t capacity;
	Object* arr;

	public :
	//constructors
	ArrayList(): size_(0),capacity(1),arr(new Object[capacity]){}

	explicit ArrayList(size_t c):size_(0),capacity(c),arr(new Object[capacity]){}
	//copy constructor
	ArrayList(const ArrayList& input): size_(input.size_),capacity(input.capacity),arr(new Object[capacity]){
		for(size_t i=0;i<size_;i++){
			arr[i] = input.arr[i];
		}
	}
	//destructor
	~ArrayList(){
		delete [] arr;
	}
	//copy assignment opperator
	ArrayList& operator=(const ArrayList& rhs){
		if(this != &rhs){
			size_ = rhs.size_;
			capacity = rhs.capacity;
			delete [] arr;
			arr = new Object[capacity];
			for(size_t i=0;i<size_;i++){
				arr[i] = rhs.arr[i];
			}
		}
		return *this;
	}
	//get the size and capacity
	size_t size()const {return size_;}

	size_t capacity_() const{return capacity;}
	//[] operator
	Object& operator[](size_t index)const{
		if(index>=size_ || index < 0){
			throw std::out_of_range("Out of range");
		}
		return arr[index];
	}
	//insert and remove functions
	void insert(size_t index, const Object& obj) {
		if(index>size_ || index < 0){
			throw std::out_of_range("Out of range");
		}
		if(size_==capacity){
			Object* temp = new Object[capacity*2];
			for(size_t i=0;i<size_;i++){
				temp[i] = arr[i];
			}
			delete [] arr;
			arr = temp;
			capacity = capacity*2;
		}
		for(size_t i=size_;i>index;i--){
			arr[i] = arr[i-1];
		}
		arr[index] = obj;
		size_++;
	}
	void remove(size_t index){
		if(index>=size_ || index < 0){
			throw std::out_of_range("Out of range");
		}
			for(size_t j=index;j<size_-1;j++){
				arr[j] = arr[j+1];
			}
			size_--;
			return;
	}
	//utility function to print the array
	void print() {
		cout << "Array" << endl;
		cout << "Size: " << size_ << endl;
		cout << "Capacity: " << capacity << endl;
		for(size_t i=0;i<size_;i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

#endif  // ARRAY_LIST_H