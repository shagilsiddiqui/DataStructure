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
bool isPalindrome(node **left,node* right){
    if(right==NULL){
        return 1;
    }
    bool l=isPalindrome(left,right->link);
    if(l==0){
        return 0;
    }
    bool k=((*left)->data==right->data);
    (*left)=(*left)->link;
    return k;
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(2);
    insert(1);
    print();
    // Delete(2);
    // print();
    //reverseIterative();
    //print();
    //ReverseRecursion(head);
    //print();
    //Del();
    //print();
    node*left=head;
    cout<<isPalindrome(&left,head);
}