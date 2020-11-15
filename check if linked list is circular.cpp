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
void insert(int data,int n){
    // if(head==NULL){
    //     head=create(data);
    //     cout<<head<<endl;
    //     return;
    // }
    // struct node* temp1=head;
    // head=create(data);
    // head->link=temp1;
    if(n==1){
        struct node* temp=create(data);
        temp->link=head;
        head=temp;
        return;
    }
    node*temp=head;
    for(int i=0;i<n-2;i++){
        temp=temp->link;
    }
    node*temp1=create(data);
    temp1->link=temp->link;
    temp->link=temp1;
    
   // cout<<head->link<<endl;
    
}
void print(){
    struct node* temp1=head;
    while(temp1!=NULL){
        cout<<temp1->data<<endl;
        temp1=temp1->link;
    }
}
bool Iscircular(){
    node*sp=head;
    node*fp=head;
    while(fp!=NULL and fp->link!=NULL){
        sp=sp->link;
        fp=fp->link->link;
        if(sp==fp){
            return 1;
        }
    }
    return 0;
}
int main()
{
    insert(5,1);
     insert(10,2);
    insert(15,1);
    insert(20,3);
    node*temp=head;
    while(temp->data!=10){
        temp=temp->link;
    }
    node*temp1=head;
    while(temp1->link!=NULL){
        temp1=temp1->link;
    }
    temp1->link=temp;
    cout<<Iscircular()<<endl;
}