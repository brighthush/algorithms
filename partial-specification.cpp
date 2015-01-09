// template partial specification

#include <iostream>

using namespace std;

template <class T1, class T2>
class Node
{
private:
    T1 val1;
    T2 val2;

public:
    Node()
    {
        cout << "T1 T2" << endl;
        cout << sizeof(T1) << endl;
    }
};

template <class T1, class T2>
class Node<T1*, T2*>
{
public:
    Node()
    {
        cout << "T1* T2*" << endl;
        cout << sizeof(T1) << endl;
    }

};

int main()
{
    Node<char*, double> node1;  // match the first template
    Node<char*, double*> node2; // match the second template which is the partial specification of the first one
    return 0;
}
