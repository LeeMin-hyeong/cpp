#include <iostream>
#include "list.h"

void LinkedList::Append(int data){
    Node *node=new Node(data);
    if(!tail){
        head=node;
        tail=node;
    }
    else{
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
}
void LinkedList::Prepend(int data){
    Node *node=new Node(data);
    if(!head){
        head=node;
        tail=node;
    }
    else{
        head->prev=node;
        node->next=head;
        head=node;
    }
}
int LinkedList::Length(){
    Node *curr=head;
    int count=0;
    while(curr!=NULL){
        curr=curr->next;
        count++;
    }
    return count;
}
void LinkedList::Print(){
    Node *curr=head;
    while(curr!=NULL){
        std::cout<<curr->data<<" ";
        curr=curr->next;
    }
    std::cout<<"\n";
}
void LinkedList::PrintReverse(){
    Node *curr=tail;
    while(curr!=NULL){
        std::cout<<curr->data<<" ";
        curr=curr->prev;
    }
    std::cout<<"\n";
}