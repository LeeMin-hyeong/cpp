class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};

class LinkedList{
public:
    Node *head;
    Node *tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void Append(int data);
    void Prepend(int data);
    int Length();
    void Print();
    void PrintReverse();
};