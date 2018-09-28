#include <iostream>
#include <memory>

using namespace std;

struct EmptyListError : runtime_error
{
    EmptyListError() : runtime_error("List is empty") {}
};

struct NotFoundError : runtime_error
{
    NotFoundError() : runtime_error("Not found") {}
};

class Node
{
public:
    Node(const int v) :
        next(nullptr),
        value(v)
    {}
    shared_ptr<Node> next;
    int value;
};

class List
{
public:
    List();
    void add(shared_ptr<Node> node);        // dodaje element na koniec listy
    shared_ptr<Node> get(const int value);  // zwraca element o wskazanej wartości

private:
    shared_ptr<Node> first;
};

List::List() :
    first(nullptr)
{}

void List::add(shared_ptr<Node> node)
{
    if(!first)
    {
        first = node;
    }
    else
    {
        shared_ptr<Node> current = first;
        while(current->next)
        {
            current = current->next;
        }
        current->next = node;
    }
}

shared_ptr<Node> List::get(const int value)
{
    if(!first)
    {
        throw EmptyListError{};
    }
    else
    {
        shared_ptr<Node> current = first;
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

int main()
{
    try
    {
        List lista;
        shared_ptr<Node> node4 = make_shared<Node>(4);
        shared_ptr<Node> node7 = make_shared<Node>(7);

        lista.add(node4);
        lista.add(make_shared<Node>(2));
        lista.add(node7);
        lista.add(make_shared<Node>(9));
        auto node = lista.get(1);
    }
    catch (runtime_error & re)
    {
        cerr << re.what() << endl;
    }

    return 0;
}

