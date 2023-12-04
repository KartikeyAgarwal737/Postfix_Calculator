#include <iostream>
#include "node.h"
using namespace std;

Node::Node(bool sentinel=true) {
    is_sentinel = sentinel;
    prev = NULL;
    next = NULL;
}

Node::Node(int v, Node* nxt, Node* prv) {
    is_sentinel = false;
    value = v;
    next = nxt;
    prev = prv;
}

bool Node::is_sentinel_node() {
    if (is_sentinel) {
        return 1;
    }
    else {
        return 0;
    }
}

int Node::get_value() {
    return value;
}