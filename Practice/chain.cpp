#include <iostream>

template <class T>
class Node{
public:
    T data;
    Node<T> *link;
    Node<T>(T d){
        data=d;
        link=NULL;
    }
};

template <class T>
class Chain{
public:
    Node<T> *last;
    void Foo(const T &d);
    void Print();
};

template <class T>
void Chain<T>::Foo(const T &d){
    Node<T> *n=new Node<T>(d);
    if(last){
        n->link=last->link;
        last->link=n;
    }
    else{
        last=n;
        n->link=n;
    }
}

template <class T>
void Chain<T>::Print(){
    Node<T> *n=last;
    do
        std::cout<<n->data<<"\n";
    while((n=n->link)!=last);
}

int main(){
    Chain<int> *c=new Chain<int>();
    c->Foo(1);
    c->Foo(2);
    c->Foo(3);
    c->Print();
}