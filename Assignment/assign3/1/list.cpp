#include <iostream>
#include "list.h"

void LinkedList::Append(int data){
    Node *node=new Node();
    node->data=data;
    node->next=NULL;
    if(head->next==NULL)
        head->next=node;
    else{
        Node *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=node;
    }
}
int LinkedList::Length(){
    Node *curr=head->next;
    int count=0;
    while(curr!=NULL){
        curr=curr->next;
        count++;
    }
    return count;
}
void LinkedList::Print(){
    Node *curr=head->next;
    while(curr!=NULL){
        std::cout<<curr->data<<" ";
        curr=curr->next;
    }
    std::cout<<"\n";
}