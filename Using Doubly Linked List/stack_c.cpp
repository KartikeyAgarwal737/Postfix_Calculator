#include "stack_c.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Constructor
Stack_C::Stack_C() {
    stk = new List();
}

// Destructor
Stack_C::~Stack_C() {
    stk->~List();
}

void Stack_C::push(int data) {
    stk->insert(data);
}

int Stack_C::pop() {
    if (stk->get_size() == 0) {
        throw runtime_error("Empty Stack");
        return -1;
    }
    stk->delete_tail();
}

int Stack_C::get_element_from_top(int idx) {
    if (stk->get_size() <= idx || idx < 0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    Node * temp = stk->get_head();
    for (int i=0; i<stk->get_size()-idx-1; i++) {
        temp = temp->next;
    }
    return temp->get_value();
}

int Stack_C::get_element_from_bottom(int idx) {
    if (stk->get_size() <= idx || idx < 0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    Node * temp = stk->get_head();
    for (int i=0; i<idx; i++) {
        temp = temp->next;
    }
    return temp->get_value();
}

void Stack_C::print_stack(bool top_or_bottom) {
    if (top_or_bottom) {
        Node * temp = stk->get_head();
        for (int i=0; i<stk->get_size(); i++) {
            temp = temp->next;
        }
        for (int i=stk->get_size()-1; i>=0; i--) {
            cout<<temp->get_value()<<endl;
            temp = temp->prev;
        }
    }
    else {
        Node * temp = stk->get_head();
        for (int i=0; i<stk->get_size(); i++) {
            cout<<temp->get_value()<<endl;
            temp=temp->next;
        }
    }
}

int Stack_C::add() {
    if (stk->get_size() < 2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = stk->delete_tail();
    int num2 = stk->delete_tail();
    stk->insert(num1+num2);
    return num1+num2;
}

int Stack_C::subtract() {
    if (stk->get_size() < 2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = stk->delete_tail();
    int num2 = stk->delete_tail();
    stk->insert(num2-num1);
    return num2-num1;
}

int Stack_C::multiply() {
    if (stk->get_size() < 2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = stk->delete_tail();
    int num2 = stk->delete_tail();
    stk->insert(num1 * num2);
    return num1 * num2;
}

int Stack_C::divide() {
    if (stk->get_size() < 2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = stk->delete_tail();
    int num2 = stk->delete_tail();
    if (num1 == 0) {
        throw runtime_error("Divide by Zero Error");
        return -1;
    }
    stk->insert(num2 / num1);
    return num2/num1;
}

List* Stack_C::get_stack() {
    return stk;
}

int Stack_C::get_size() {
    return stk->get_size();
}