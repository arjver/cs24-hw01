// intlist.cpp
// Implements class IntList
// Arjun Verma, 16.Jan.2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    
    Node* p = source.head;
    while (p != nullptr) {
        push_back(p->info);
        p = p->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* p = head;
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int s = 0;
    Node* p = head;
    while (p != nullptr) {
        s += p->info;
        p = p->next;
    }
    return s;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* p = head;
    while (p != nullptr) {
        if (p->info == value) {
            return true;
        }
        p = p->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) {
        return 0;
    }
    
    int max = head->info;
    Node* p = head->next;
    while (p != nullptr) {
        if (p->info > max) {
            max = p->info;
        }
        p = p->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr) {
        return 0.0;
    }
    
    int n = count();
    if (n == 0) {
        return 0.0;
    }
    
    return 1.0 * sum() / n;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = head;
    head = n;
    
    if (tail == nullptr) {
        tail = n;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* n = new Node;
    n->info = value;
    n->next = nullptr;
    
    if (head == nullptr) {
        head = n;
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
}

// return count of values
int IntList::count() const {
   int n = 0;
   Node* p = head;
   while (p != nullptr) {
       n++;
       p = p->next;
   }
   return n;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
        return *this;
    }
    
    Node* p = head;
    while (p != nullptr) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    
    head = nullptr;
    tail = nullptr;
    
    p = source.head;
    while (p != nullptr) {
        push_back(p->info);
        p = p->next;
    }
    
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

