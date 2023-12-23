#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
void displayforward(node *head){
    cout<<"Forward order: ";
    node *temp;
    temp=head;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void displayReverse(node *tail){
    cout<<"Reverse order: ";
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
        cout<<"Enter element "<<i+1<<": ";
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
    cout<<"\nDo you want to perform any operation?(yes-1, no-0): ";
    cin>>choice;
    while(choice){
        int option, pos, count=0;
        cout<<"\nWhat operation you want to perform:\n1. Insertion at beginning\n2. Insertion at end \n3. Insertion at position\n4. Deletion at beginning\n5. Deletion at end\n6. Deletion at position\n7. Reverse the linked list\nEnter your option: ";
        cin>>option;
        node *newnode = new node;
        switch(option){
            case 1:
                cout<<"Enter element to be inserted: ";
                cin>>newnode->data;
                head->prev=newnode;
                newnode->prev=0;
                newnode->next=head;
                head=newnode;
                displayforward(head);
                displayReverse(tail);
                break;
            case 2:
                cout<<"Enter element to be inserted: ";
                cin>>newnode->data;
                tail->next=newnode;
                newnode->prev=tail;
                newnode->next=0;
                tail=newnode;
                displayforward(head);
                displayReverse(tail);
                break;
            case 3:{
                cout<<"Enter position to be inserted: ";
                cin>>pos;
                cout<<"Enter element to be inserted: ";
                cin>>newnode->data;
                node *temp, *previous;
                temp=head;
                while(count<pos-1){
                    previous=temp;
                    temp=temp->next;
                    count++;
                }
                temp->prev=newnode;
                newnode->next=temp;
                newnode->prev=previous;
                previous->next=newnode;
                displayforward(head);
                displayReverse(tail);
                break;
            }
                
        }
        cout<<"\nDo you want to perform any operation?(yes-1, no-0): ";
        cin>>choice;
    }
    return 0;
}