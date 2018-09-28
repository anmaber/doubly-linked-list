#pragma once

#include "node.hpp"
#include "exceptions.hpp"

using namespace std;

template<class T>
class List
{
public:
    List();
    void addLast(shared_ptr<Node<T>> node);        // dodaje element na koniec listy
    void addFirst(shared_ptr<Node<T>> node);
    shared_ptr<Node<T>> get(const T value);  // zwraca element o wskazanej wartości
    shared_ptr<Node<T>> getBackward(const T value);

private:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
};

template <class T>
List<T>::List() :
    head(nullptr),
    tail(nullptr)
{}

template <class T>
void List<T>::addLast(shared_ptr<Node<T>> node)
{
    if(!head)
    {
        head = node;
        tail = head;
    }
    else
    {
        shared_ptr<Node<T>> current = tail;
        current->next = node;
        node->previous = current;
        tail=node;
    }
}

template <class T>
void List<T>::addFirst(shared_ptr<Node<T>> node)
{
    if(!tail)
    {
        tail = node;
        head = tail;
    }
    else
    {
        shared_ptr<Node<T>> current = head;
        current->previous = node;
        node->next = current;
        head=node;
    }
}

template <class T>
shared_ptr<Node<T>> List<T>::get(const T value)
{
    if(!head)
    {
        throw EmptyListError{};
    }
    else
    {
        shared_ptr<Node<T>> current = head;
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

template <class T>
shared_ptr<Node<T>> List<T>::getBackward(const T value)
{
    if(!tail)
    {
        throw EmptyListError{};
    }
    else
    {
       shared_ptr<Node<T>> current = tail;
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
