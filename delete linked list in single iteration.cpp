#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node* link;
};
struct node* head=NULL;
struct node* create(int n){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->link=NULL;
    return temp;
}
void insert(int n){
    if(head==NULL){
        head=create(n);
        cout<<head<<endl;
        return;
    }
    struct node* temp1=head;
    head=create(n);
    head->link=temp1;
   // cout<<head->link<<endl;
    
}
void print(){
    struct node* temp1=head;
    while(temp1!=NULL){
        cout<<temp1->data<<endl;
        temp1=temp1->link;
    }
}
void Del(){
    node*next=head;
    while(head!=NULL){
        next=head->link;
        free(head);
        head=next;
    }
}


int main()
{
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    print();
    // Delete(2);
    // print();
    //reverseIterative();
    //print();
    //ReverseRecursion(head);
    //print();
    Del();
    print();
}