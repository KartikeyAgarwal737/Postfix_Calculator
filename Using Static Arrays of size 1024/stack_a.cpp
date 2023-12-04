#include "stack_a.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Stack_A::Stack_A () {
    stk[1024] = {0};
    size = 0;
}

void Stack_A::push(int data) {
    if (size==1024) {
        throw runtime_error ("Stack Full");
    }
    stk[size] = data;
    size++;
}

int Stack_A::pop() {
    if (size==0) {
        throw runtime_error("Empty Stack");
        return -1;
    }
    int dummy = stk[size-1];
    stk[size-1] = 0;
    size--;
    return dummy;
}

int Stack_A::get_element_from_top(int idx) {
    if (size <= idx || idx < 0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    return stk[size-idx-1];
}

int Stack_A::get_element_from_bottom(int idx) {
    if (size <= idx || idx < 0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    return stk[idx];
}

void Stack_A::print_stack(bool top_or_bottom) {
    if (top_or_bottom) {
        for (int i=size-1; i>=0; i--) {
            cout<<stk[i]<<endl;
        }
    }
    else {
        for (int i=0; i<size; i++) {
            cout<<stk[i]<<endl;
        }
    }
}

int Stack_A::add() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_A::pop();
    int num2 = Stack_A::pop();
    stk[size] = num1+num2;
    size++;
    return stk[size-1];
}

int Stack_A::subtract() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_A::pop();
    int num2 = Stack_A::pop();
    stk[size] = num2-num1;
    size++;
    return stk[size-1];
}

int Stack_A::multiply() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_A::pop();
    int num2 = Stack_A::pop();
    stk[size] = num1*num2;
    size++;
    return stk[size-1];
}

int Stack_A::divide() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_A::pop();
    int num2 = Stack_A::pop();
    if (num1 == 0) {
        throw runtime_error("Divide by Zero Error");
        return -1;
    }
    stk[size] = num2 / num1;
    size++;
    return stk[size-1];
}

int* Stack_A::get_stack() {
    return stk;
}

int Stack_A::get_size() {
    return size;
}