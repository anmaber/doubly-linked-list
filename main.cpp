#include "list.hpp"

using namespace std;


int main()
{
    try
    {
        List lista;
        shared_ptr<Node> node4 = make_shared<Node>(4);
        shared_ptr<Node> node7 = make_shared<Node>(7);

        lista.addLast(node4);
        lista.addFirst(make_shared<Node>(2));
        lista.addLast(node7);
        lista.addLast(make_shared<Node>(9));
        auto node = lista.get(9);
        auto node2 = lista.getBackward(2);
    }
    catch (runtime_error & re)
    {
        cerr << re.what() << endl;
    }

    return 0;
}

