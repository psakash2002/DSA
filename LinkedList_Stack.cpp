#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
node *top=0;
void push(){
    node* newnode=new node;
    cout<<"Enter element to be inserted: ";
    cin>>newnode->data;
    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top==0){
        cout<<"stack underflow!!";
    }
    else{
        node *temp=top;
        top=top->next;
        cout<<"Popped element is: "<<temp->data;
        delete(temp);
    }
}
void peek(){
    if(top==0){
        cout<<"Stack underflow!!";
    }
    else{
        cout<<"The top element is: "<<top->data;
    }
}
void display(){
    if(top==0){
        cout<<"Stack underflow!!";
    }
    node *temp=top;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int choice=1, operation;
    do{
        cout<<"\n1.push\n2.pop\n3.peek\n4.display\n";
        cout<<"Select what operation to be performed:";
        cin>>operation;
        switch(operation){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                cout<<"Check your option\n";
        }
        cout<<"\nWant to continue? Yes-1/No-0: ";
        cin>>choice;
    }while(choice!=0);
}