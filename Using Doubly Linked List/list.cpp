#include "list.h"
#include <iostream>
using namespace std;

List::List() {
    size = 0;
    sentinel_head = new Node ();
    sentinel_tail = new Node ();
}

List::~List() {
    Node * temp = sentinel_head->next;
    while (temp->next != sentinel_tail->next) {
        Node * dummy = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
        temp = dummy;
    }

    sentinel_head->next = NULL;
    sentinel_tail->prev = NULL;
    delete sentinel_head;
    delete sentinel_tail;
}

// Insert an element at the tail of the linked list 
void List::insert(int v) {
    if (size == 0) {
        Node * temp = new Node (v, sentinel_tail, sentinel_head);
        size++;
    }
    else {
        Node * temp = new Node(v, sentinel_tail, sentinel_tail->prev);
        size++;
    }
    
}

// Delete the tail of the linked list and return the value
// You need to delete the valid tail element, not the sentinel
int List::delete_tail() {
    int deleted_value = sentinel_tail->prev->get_value();
    sentinel_tail->prev->prev->next = sentinel_tail;
    sentinel_tail->prev = sentinel_tail->prev->prev;
    sentinel_tail->prev->next = NULL;
    sentinel_tail->prev->prev = NULL;
    size--;
    return deleted_value;
}

// Return the size of the linked list 
// Do not count the sentinel elements
int List::get_size() {
    return size;
}

// Return a pointer to the sentinel head of the linked list 
Node* List::get_head() {
    return sentinel_head->next;
}