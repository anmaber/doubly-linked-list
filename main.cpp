#include "list.hpp"
#include <string>

using namespace std;


int main()
{
    try
    {
        using type=string;

        List<type> lista;
        auto node4 = make_shared<Node<type>>("Ania");
        auto node7 = make_shared<Node<type>>("gosia");

        lista.addLast(node4);
        lista.addFirst(make_shared<Node<type>>("kuba"));
        lista.addLast(node7);
        lista.addLast(make_shared<Node<type>>("jaca"));
        auto node = lista.get("gosia");
        auto node2 = lista.getBackward("Ania");
    }
    catch (runtime_error & re)
    {
        cerr << re.what() << endl;
    }

    return 0;
}

