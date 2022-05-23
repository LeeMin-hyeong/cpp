class Node{
public:
    int data;
    Node *next;
};

class LinkedList{
public:
    Node *head;
    LinkedList(){
        head=new Node();
    }
    void Append(int data);
    void Prepend(int data);
    int Length();
    void Print();
};