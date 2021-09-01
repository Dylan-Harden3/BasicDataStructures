#include <iostream>
#include "array_list.h"
using namespace std;
int main() {
// make an empty list
ArrayList<int> list;
// insert 0-10
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
ArrayList<int> list2(list);
list2.print();
return 0;
}
