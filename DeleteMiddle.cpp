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
int middle(){
    node*sp=head;
    node*fp=head;
    while(fp!=NULL and fp->link!=NULL ){
        sp=sp->link;
        fp=fp->link->link;
        //cout<<sp->data<<endl;
        // cout<<fp->data<<endl;
    }
    return sp->data;
}
void DelMiddle(){
    node*sp=head;
    node*fp=head;
    node*prev=head;
    while(fp!=NULL and fp->link!=NULL ){
        prev=sp;
        sp=sp->link;
        fp=fp->link->link;
        //cout<<sp->data<<endl;
        // cout<<fp->data<<endl;
    }
    prev->link=sp->link;
    free(sp);
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
    cout<<middle()<<endl;
    DelMiddle();
    print();
}