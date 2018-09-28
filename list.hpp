#pragma once

#include "node.hpp"
#include "exceptions.hpp"

using namespace std;

class List
{
public:
    List();
    void addLast(shared_ptr<Node> node);        // dodaje element na koniec listy
    void addFirst(shared_ptr<Node> node);
    shared_ptr<Node> get(const int value);  // zwraca element o wskazanej wartości
    shared_ptr<Node> getBackward(const int value);

private:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
};

List::List() :
    head(nullptr),
    tail(nullptr)
{}


void List::addLast(shared_ptr<Node> node)
{
    if(!head)
    {
        head = node;
        tail = head;
    }
    else
    {
        shared_ptr<Node> current = tail;
        current->next = node;
        node->previous = current;
        tail=node;
    }
}

void List::addFirst(shared_ptr<Node> node)
{
    if(!tail)
    {
        tail = node;
        head = tail;
    }
    else
    {
        shared_ptr<Node> current = head;
        current->previous = node;
        node->next = current;
        head=node;
    }
}

shared_ptr<Node> List::get(const int value)
{
    if(!head)
    {
        throw EmptyListError{};
    }
    else
    {
        shared_ptr<Node> current = head;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while(current);

        throw NotFoundError{};
        return nullptr;
    }
}

shared_ptr<Node> List::getBackward(const int value)
{
    if(!tail)
    {
        throw EmptyListError{};
    }
    else
    {
       shared_ptr<Node> current = tail;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->previous.lock();
            }
        } while(current);

        throw NotFoundError{};
        return nullptr;
    }
}
