#include <iostream>
#include "doubly_linked_list.h"
using namespace std;
int main() {
  // make an empty list
	DoublyLinkedList<int> list;
	for(int i=1;i<11;i++){
    list.insert(i-1,i);
}
list.print();
cout << "Removing odd numbers" << endl;
for(int i=0;i<list.size();i++){
    if(list[i] % 2 == 1){
        list.remove(i);
    }
}
list.print();
cout << "Make a copy of the list" << endl;
cout << "new list" << endl;
DoublyLinkedList<int> list2(list);
list2.print();
	return 0;
}