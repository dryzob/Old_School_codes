// Linked list
#include <iostream>
#include <stdexcept>

class MyList;

class Node {
public:
    Node() : _data{0}, _next{nullptr} {};
    Node(int data) : _data{data}, _next{nullptr} {};
    Node(int data, Node* next) : _data{data}, _next{next} {};
    friend class MyList;
private:
    int _data;
    Node* _next;
};

class MyList {
public:
    MyList() : _head{nullptr}, _count{0} {};
    void addFront(int data);
    int front() const;
    int size() const;
    void removeFront();
private:
    Node* _head;
    int _count;
};

void MyList::addFront(int data) {
    Node* n = new Node(data);
    if (_head == nullptr) {
        _head = n;
        return;
    }
    n->_next = _head;
    _head = n;
}

int MyList::front() const {
    if (_head == nullptr) {
        throw std::runtime_error("Empty list");
    }
    return _head->_data;
}

int MyList::size() const {
    int count = 0;
    Node* n = _head;
    while (n != nullptr) {
        count++;
        n = n->_next;
    }
    return count;
}

void MyList::removeFront() {
    if (_head == nullptr) return;
    Node* n = _head;
    _head = n->_next;
    delete n;
}

int main() {

    MyList lst;
    lst.addFront(1);
    std::cout << lst.front() << std::endl; // Prints 1
    lst.addFront(2);
    std::cout << lst.front() << std::endl; // Prints 2
    std::cout << "Number of Nodes: " << lst.size() << std::endl; // Print size
    lst.removeFront();
    std::cout << lst.front() << std::endl;

    return 0;
}