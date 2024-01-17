#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *prev;
    node *next;
};
void displayList(node *tail){
    node *temp;
    temp=tail->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail->next);
    cout<<"\nThe next element is "<<tail->next->data<<"\n";
}
void displayReverse(node *tail){
    node *temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    while(temp!=tail);
}
int main(){
    int size, perform, choice;
    node *tail=0;
    cout<<"Enter size of the list: ";
    cin>>size;
    for(int i=0;i<size;i++){
        node *newnode = new node;
        cout<<"Enter element "<<i+1<<":";
        cin>>newnode->data;
        if(tail==0){
            newnode->next = newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            newnode->prev=tail;
        }
        tail=newnode;
        tail->next->prev = tail;
    }
    displayList(tail);
    displayReverse(tail);
    cout<<"\nDo you want to perform any operation? (Yes-1/No-0)";
    cin>>perform;
    while(perform){
        int pos, count=0;
        node *previous;
        node *newnode = new node;
        cout<<"\nWhat operation you want to perform:\n1. Insertion at beginning\n2. Insertion at end \n3. Insertion at position\n4. Deletion at beginning\n5. Deletion at end\n6. Deletion at position\n7. Reverse the linked list\nEnter your option: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to be inserted: ";
                cin>>newnode->data;
                newnode->prev=tail;
                newnode->next=tail->next;
                tail->next->prev=newnode;
                tail->next=newnode;
                displayList(tail);
                displayReverse(tail);
                break;
            case 2:
                cout<<"\nEnter element to be inserted: ";
                cin>>newnode->data;
                newnode->prev=tail;
                newnode->next=tail->next;
                tail->next->prev=newnode;
                tail->next=newnode;
                tail=newnode;
                displayList(tail);
                displayReverse(tail);
                break;
            case 3:
                cout<<"\nEnter position to be inserted: ";
                cin>>pos;
                cout<<"\nEnter element to be inserted: ";
                cin>>newnode->data;
                node *temp;
                temp=tail->next;
                while(count<pos-1){
                    previous=temp;
                    temp=temp->next;
                    count++;
                }
                newnode->prev=previous;
                newnode->next=temp;
                temp->prev=newnode;
                previous->next=newnode;
                displayList(tail);
                displayReverse(tail);
                break;
            case 4:
                tail->next->next->prev=tail->next->prev;
                tail->next=tail->next->next;
                displayList(tail);
                displayReverse(tail);
                break;
            case 5:
                tail->prev->next=tail->next;
                tail=tail->prev;
                tail->next->prev=tail;
                displayList(tail);
                displayReverse(tail);
                break;
            case 6:
                cout<<"\nEnter position to be deleted: ";
                cin>>pos;
                temp=tail->next;
                while(count<pos-1){
                    previous=temp;
                    temp=temp->next;
                    count++;
                }
                temp->next->prev=previous;
                previous->next=temp->next;
                displayList(tail);
                displayReverse(tail);
                break;
            case 7:
                node *currentnode, *nextnode;
                node *tempo;
                tempo=tail->next;
                currentnode=nextnode=tail->next;
                while(currentnode!=tail){
                    nextnode=currentnode->next;
                    currentnode->next=currentnode->prev;
                    currentnode->prev=nextnode;
                    currentnode=nextnode;
                }
                
                currentnode->next=currentnode->prev;
                currentnode->prev=tempo;
                tail=tempo;
                displayList(tail);
                displayReverse(tail);
                break;
            default:
                cout<<"Enter correct option";
        }
        cout<<"\nWant to continue?(Yes-1/No-0)";
        cin>>perform;
    }
    
    
    return 0;
}