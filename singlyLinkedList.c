#include <stdio.h>
#include <stdlib.h>
 struct node
 {
    int data;
    struct node *next;
 };
 int main(){
    struct node *head, *temp, *newnode;
    int n, count=0;
    head=0;
    printf("Enter number of elements to be added: ");
    scanf("%d", &n);
    while(count<n){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ", count+1);
        scanf("%d", &newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        count++;
    }
    temp=head;
    while(temp!=0){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    return 0;
 }
 