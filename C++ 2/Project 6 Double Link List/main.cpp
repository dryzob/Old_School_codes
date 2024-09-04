#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

void test(){
    DoublyLinkedList<int> dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    DoublyLinkedList<int> dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(1, 5);
    
    //dll.remove(2);
    
    cout << endl <<  "Original:" << endl;
    dll.print();
    cout << endl;
    
    cout << "Constructed copy:" << endl;
    dllCopy.print();
    cout << endl;
    
    dll = dllCopy;
    cout << "Operator copy:" << endl;
    dll.print();
    cout << endl;
}

int main(){
    test();
    
    return 0;
}