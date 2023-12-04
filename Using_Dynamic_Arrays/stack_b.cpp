#include "stack_b.h"
#include <iostream>
#include <stdexcept>
using namespace std;


Stack_B::Stack_B() {
    capacity = 1024;
    size = 0;
    stk = new int[capacity];
}

Stack_B::~Stack_B() {
    delete[] stk;
}

void Stack_B::push(int data) {
    if (capacity == size) {
        capacity*=2;
        int * dummy = new int[capacity]();
        for (int i=0; i<size; i++) {
            dummy[i] = stk[i];
        }
        delete[] stk;
        stk = dummy;
    }
    stk[size] = data;
    size++;
}

int Stack_B::pop() {
    if (size < capacity/4 && capacity>1024) {
        capacity/=2;
        int * dummy = new int[capacity];
        for (int i=0; i<size; i++) {
            dummy[i] = stk[i];
        }
        delete[] stk;
        stk = dummy;
    }
    if (size==0) {
        throw runtime_error("Empty Stack");
        return -1;
    }
    size--;
    return stk[size];
}

int Stack_B::get_element_from_top(int idx) {
    if (size <= idx || idx < 0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    return stk[size-idx-1];
}

int Stack_B::get_element_from_bottom(int idx) {
    if (size <= idx || idx < 0) {
        throw runtime_error("Index out of range");
        return -1;
    }
    return stk[idx];
}

void Stack_B::print_stack(bool top_or_bottom) {
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

int Stack_B::add() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_B::pop();
    int num2 = Stack_B::pop();
    stk[size] = num1+num2;
    size++;
    return stk[size-1];
}

int Stack_B::subtract() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_B::pop();
    int num2 = Stack_B::pop();
    stk[size] = num2-num1;
    size++;
    return stk[size-1];
}

int Stack_B::multiply() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_B::pop();
    int num2 = Stack_B::pop();
    stk[size] = num1*num2;
    size++;
    return stk[size-1];
}

int Stack_B::divide() {
    if (size<2) {
        throw runtime_error("Not Enough Arguments");
        return -1;
    }
    int num1 = Stack_B::pop();
    int num2 = Stack_B::pop();
    if (num1 == 0) {
        throw runtime_error("Divide by Zero Error");
        return -1;
    }
    stk[size] = num2 / num1;
    size++;
    return stk[size-1];
}

int* Stack_B::get_stack() {
    return stk;
}

int Stack_B::get_size() {
    return size;
}

int main () {
    Stack_B s;
    s.push(2);
    cout<<s.get_element_from_bottom(0);
    cout<<s.get_element_from_bottom(0);
    cout<<0;

    return 0;

}