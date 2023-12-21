#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
void display(struct node *current){
    while(current!=0){
        cout<<current->data<<" ";
        current=current->next;
    }
}
int main(){
    int n;
    cout<<"Enter number of elements to be added: ";
    cin>>n;
    struct node *newnode, *temp, *head=0;
    for(int i=0;i<n;i++){
        cout<<"Enter element " << i+1 << ": ";
        node *newnode=new node;
        cin>>newnode->data;
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    display(head);
    int choice, toContinue;
    cout<<"\nWant to perform any operation?(Yes-1/No-0): ";
    cin>>toContinue;
    while(toContinue){
        int pos, count=0;
        cout<<"\nWhat operation you want to perform:\n1. Insertion at beginning\n2. Insertion at end \n3. Insertion at position\n4. Deletion at beginning\n5. Deletion at end\n6. Deletion at position\n7. Reverse the linked list\n";
        cin>>choice;
        node *newnode=new node;
        node *prev;
        switch(choice){
        case 1:
            cout<<"\nEnter element to be inserted: ";
            cin>>newnode->data;
            newnode->next=head;
            head=newnode;
            display(head);
            break;
        case 2:
            cout<<"\nEnter element to be inserted: ";
            cin>>newnode->data;
            newnode->next=0;
            temp=head;
            while(temp->next!=0){
                temp=temp->next;
            }
            temp->next=newnode;
            display(head);
            break;
        case 3:
            display(head);
            cout<<"\nEnter position to be inserted: ";
            cin>>pos;
            cout<<"Enter number to be inserted: ";
            cin>>newnode->data;
            temp=head;
            while(count<pos-2){
                temp=temp->next;
                count++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            display(head);
            break;
        case 4:
            display(head);
            cout<<endl;
            temp=head;
            head=temp->next;
            delete temp;
            display(head);
            break;
        case 5:
            temp=head;
            while(temp->next!=0){
                prev=temp;
                temp=temp->next;
            }
            prev->next=0;
            delete temp;
            display(head);
            break;
        case 6:
            cout<<"\nEnter position to be deleted: ";
            cin>>pos;
            temp=head;
            while(count<pos-1){
                prev=temp;
                temp=temp->next;
                count++;
            }
            prev->next=temp->next;
            delete temp;
            display(head);
            break;
        case 7:
            node *prev, *current, *nextnode;
            prev=0;
            current=nextnode=head;
            while(nextnode!=0){
                nextnode=nextnode->next;
                current->next=prev;
                prev=current;
                current=nextnode;
            }
            head=prev;
            display(head);
            break;
    }
        cout<<"\nWant to perform any operation?(Yes-1/No-0): ";
        cin>>toContinue;
    }
    
}