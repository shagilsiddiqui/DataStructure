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
void Delete(int n){
    if(n==1){
        node* temp=head;
        head=temp->link;
        free(temp);
        return;
    }
    struct node* temp=head;
    for(int i=0;i<n-2;i++){
        temp=temp->link;
    }
node*t=temp->link;
    temp->link=t->link;
    free(t);
}

void DelDuplicateSorted(){
    node*temp=head;
    while(temp->link!=NULL){
        if(temp->data==temp->link->data){
            node*temp1=temp->link;
            temp->link=temp->link->link;
            free(temp1);
        }
        else{
            temp=temp->link;
        }
        
    }
}
void DelDuplicate(){
    set<int>s;
    node*temp=head;
    node*prev=head;
    while(temp!=NULL){
        if(s.count(temp->data)){
             prev->link=temp->link;
             free(temp);
        }
        else{
            s.insert(temp->data);
            prev=temp;
        }
        temp=prev->link;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(2);
    //print();
    // Delete(2);
    // print();
    //reverseIterative();
    //print();
    //DelDuplicateSorted();
    //print();
    DelDuplicate();
    print();
    
}