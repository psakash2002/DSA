#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
void displayforward(node *head){
    node *temp;
    temp=head;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void displayReverse(node *tail){
    node *temp;
    temp=tail;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}
int main(){
    node *head, *tail, *temp;
    int n, choice;
    head=0;
    cout<<"Enter number of elements to be inserted: ";
    cin>>n;
    for(int i=0;i<n;i++){
        node *newnode = new node;
        cout<<"\nEnter element "<<i+1<<": ";
        cin>>newnode->data;
        if(head==0){
            newnode->prev=0;
            newnode->next=0;
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            newnode->next=0;
            temp=temp->next;
        }
        tail=newnode;
    }
    displayforward(head);
    displayReverse(tail);
    return 0;
}