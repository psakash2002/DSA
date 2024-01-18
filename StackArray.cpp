#include<bits/stdc++.h>
using namespace std;
#define N 5
int stack[N];
int top=-1;
void push(){
    int element;
    cout<<"\nEnter element to be pushed: ";
    cin>>element;
    if(top==-1){
        top++;
        ::stack[top]=element;
    }
    else{
        top++;
        ::stack[top]=element;
    }
}
void pop(){
    int popped;
    if(top==-1){
        cout<<"\nNo element to be popped";
    }
    else{
        popped=::stack[top];
        top=top-1;
        cout<<"Element popped: "<<popped;
    }
    
}
void peek(){
    if(top==-1){
        cout<<"\nNo elements in the array";
    }
    else{
        cout<<"The top element is: "<<::stack[top];
    }
}
void display(){
    for(int i=top;i>=0;i--){
        cout<<::stack[i]<<" ";
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
    return 0;
}