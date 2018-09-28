#pragma once

#include <memory>

using namespace std;

template<class T>
class Node
{
public:
    Node(const T v) :
        next(nullptr),
        value(v)
    {}
    shared_ptr<Node> next;
    weak_ptr<Node> previous;
    T value;
};
