#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

void displayList(node *tail){
    node *temp=tail;
    temp=temp->next;
    while(temp->next != tail->next){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    temp=temp->next;
    cout<<"\nNext element is "<<temp->data;
}

int main(){
    node *tail, *temp;
    tail=0;
    int n, perform, choice;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        node *newnode=new node;
        cout<<"Enter element "<<i+1<<":";
        cin>>newnode->data;
        newnode->next=0;
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
    }
    displayList(tail);
    cout<<"\nDo You want to perform any operations?(Yes:1/No:0): ";
    cin>>perform;
    while(perform){
        int pos, count=0;
        node *temp, *prev;
        node *newnode=new node;
        cout<<"\nWhat operation you want to perform:\n1. Insertion at beginning\n2. Insertion at end \n3. Insertion at position\n4. Deletion at beginning\n5. Deletion at end\n6. Deletion at position\n7. Reverse the linked list\nEnter your option: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter element: ";
            cin>>newnode->data;
            newnode->next=tail->next;
            tail->next=newnode;
            displayList(tail);
            break;
        
        case 2:
            cout<<"Enter element: ";
            cin>>newnode->data;
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
            displayList(tail);
            break;
        case 3:
            cout<<"Enter position to be entered: ";
            cin>>pos;
            cout<<"Enter data to be inserted: ";
            cin>>newnode->data;
            temp=tail->next;
            while(count<pos-2){
                temp=temp->next;
                count++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            displayList(tail);
            break;
        case 4:
            tail->next=tail->next->next;
            displayList(tail);
            break;
        case 5:
            temp=tail->next;
            while(temp->next != tail->next){
                prev=temp;
                temp=temp->next;
            }
            prev->next=tail->next;
            tail=prev;
            displayList(tail);
            break;
        case 6:
            cout<<"Enter position to be deleted: ";
            cin>>pos;
            temp=tail->next;
            while(count<pos-1){
                prev=temp;
                temp=temp->next;
                count++;
            }
            prev->next=temp->next;
            displayList(tail);
            break;
        case 7:
            node *prevnode, *nextnode, *currentnode;
            currentnode=tail->next;
            prevnode=0;
            nextnode=currentnode->next;
            while(currentnode!=tail){
                prevnode=currentnode;
                currentnode=nextnode;
                nextnode=nextnode->next;
                currentnode->next=prevnode;
            }
            nextnode->next=tail;
            tail=nextnode;
            displayList(tail);
            break;
        }
        cout<<"\nDo You want to perform any operations?(Yes:1/No:0): ";
        cin>>perform;
    }
    return 0;
}