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
}