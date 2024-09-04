#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>

template<typename T>
struct node {
    T data;
    node<T>* next = nullptr;
    node<T>* prev = nullptr;
};


template<typename T>
class DoublyLinkedList {
    public: 
    
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& objToCopy);
    DoublyLinkedList& operator=(const DoublyLinkedList& objToCopy);
    void push(T data);
    void pop();
    int size() const;
    void print() const;
    T& at(int idx) const;
    void insert(T data, int pos);
    void remove(int pos);
    
    private:
    node<T>* head;
    node<T>* tail;
    T numElements = 0;
    
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    numElements = 0;
    //std::cout << "Constructor" << std::endl;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (numElements > 0) {
        pop();
    }
    //std::cout << "Deconstructor" << std::endl;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& objToCopy) {
    head = nullptr;
    tail = nullptr;
    numElements = 0;
    for (int i = 0; i < objToCopy.size(); i++) {
        push(objToCopy.at(i));
    }
    //std::cout << "Copy Constructor" << std::endl;
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& objToCopy) {
    while(numElements > 0)
        pop();
    
    for(int i = 0; i < objToCopy.size(); i++){
    push(objToCopy.at(i));
    }
} 

template<typename T>
void DoublyLinkedList<T>::push(T data) {
    numElements++;
    // Check for empty list (first element)
    if (head == nullptr) {
        head = new node<T>;
        tail = head;
        tail->data = data;
        return;
    }
    
    node<T>* temp = tail;
    // Adding to end of list
    temp->next = new node<T>;
    temp->next->prev = temp;
    temp->next->data = data;
    tail = temp->next;
}

template<typename T>
void DoublyLinkedList<T>::pop() {
    // check if single item list
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
        numElements--;
        //std::cout << "popped last" << std::endl;
        return;
    }
    //std::cout << "Elements: " << numElements << std::endl;
    tail = tail->prev; // move tail back one
    delete tail->next; // delete last item
    tail->next = nullptr;
    numElements--;
    
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return numElements;
}

template<typename T>
void DoublyLinkedList<T>::print() const {
    node<T>* currentNode = head;
    
    std::cout << "Foward elements:    | ";
    while (currentNode != nullptr) { // use while loop instead
        std::cout << currentNode->data << " | ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
    
    currentNode = tail;
    std::cout << "Backwards elements: | ";
    while (currentNode != nullptr) { // use while loop instead
        std::cout << currentNode->data << " | ";
        currentNode = currentNode->prev;
    }
    std::cout << std::endl;
}

template<typename T>
T& DoublyLinkedList<T>::at(int idx) const {
    //std::cout << "NOW IN AT()" << std:: endl;
    int currentIndex = 0; // holds current position
    node<T>* currentNode = head;
    // Loop from head to find index
    while(true) {
    if (currentIndex == idx) {
        return currentNode->data;
    }
    
    currentIndex++;
    currentNode = currentNode->next;
}
}

template<typename T>
void DoublyLinkedList<T>::insert(T data, int pos) {
    node<T>* newNode;
    node<T>* currentNode = head;
    int currentIndex = 0;
    
    if ((pos > size() - 1) || (pos < 0)) {
        std::cout << "INSERT ERROR: OUT OF BOUNDS" << std::endl;
        return;
    }
    
    if (pos == 0) {
        newNode = new node<T>;
        newNode->next = currentNode;
        currentNode->prev = newNode;
        newNode->data = data;
        head = newNode;
        return;
    }
    
    // Find the desired position
    while(currentIndex != pos) {
        currentIndex++;
        currentNode = currentNode->next;
    }
    
    newNode = new node<T>;
    newNode->next = currentNode;
    currentNode->prev->next = newNode;
    newNode->prev = currentNode->prev;
    currentNode->prev = newNode;
    newNode->data = data;
    numElements++;
}

template<typename T>
void DoublyLinkedList<T>::remove(int pos) {
    node<T>* currentNode = head;
    int currentIndex = 0;
    
    if ((pos > size() - 1) || (pos < 0)) {
        std::cout << "REMOVE ERROR: OUT OF BOUNDS" << std::endl;
        return;
    }
    
    if (pos == 0) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        numElements--;
        return;
    }
    
    // Find the desired position
    while (currentIndex != pos) {
        currentIndex++;
        currentNode = currentNode->next;
        if (currentNode == tail) {
            pop();
            return;
        }
    }
    
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
    
    delete currentNode;
    currentNode->next = nullptr;
    currentNode->prev = nullptr;
    numElements--;
}

#endif