#include <iostream>

class DblList;
class DblListNode{
    friend class DblList;
    private:
        int data;
        DblListNode *left, *right;
};

class DblList{
    public:
        DblList();
        void add(int data);
        void PrintReverse();
    private:
        DblListNode *first;
};

void DblList::add(int data){
    DblListNode *n=new DblListNode();
    n->data=data;
    if(first!=NULL){
        first=n;
        n->left=first;
        n->right=first;
    }
    else{
        first->left=n;
        n->right=first;
    }
}

DblList::DblList(){
    first=NULL;
}

void DblList::PrintReverse(){
    DblListNode *n=first;

}

int main(){
    DblList *list=new DblList();
    list->add(1);
}

