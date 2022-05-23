#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node *link;
    inline Node(int d) {
        data = d;
        link = NULL;
    }
};

class Chain {
    public:
    Node *last;
    Chain(){}
    void Foo(const int& d) {
        Node *n = new Node(d);
    if(last) {
        n -> link = last -> link;
        last -> link = n;
    } else {
        last = n;
        n -> link = n;
    }
    }
    void Print() {
        Node *n = last;
    while(!(n = n -> link)) {
        cout << n -> data << endl;
    }
    }
};

// void Chain::Foo(const int& i) {
//     Node *n = new Node(i);
//     if(last) {
//         n -> link = last -> link;
//         last -> link = n;
//     } else {
//         last = n;
//         n -> link = n;
//     }
// }

// void Chain::Print() {
//     Node *n = last;
//     while(!(n = n -> link)) {
//         cout << n -> data << endl;
//     }
// }

int main() {
    Chain c;
    c.Foo(4);
    c.Foo(3);
    c.Foo(2);
    c.Foo(1);
    c.Print();
}