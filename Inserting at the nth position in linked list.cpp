/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
int main()
{
    insert(5,1);
     insert(10,2);
    insert(15,1);
    insert(20,3);
    print();
}
