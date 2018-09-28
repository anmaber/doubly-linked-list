#pragma once

#include <memory>

using namespace std;

class Node
{
public:
    Node(const int v) :
        next(nullptr),
        value(v)
    {}
    shared_ptr<Node> next;
    weak_ptr<Node> previous;
    int value;
};
