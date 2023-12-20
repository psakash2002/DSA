#include <stdio.h>
#include <stdlib.h>
 struct node
 {
    int data;
    struct node *next;
 };
 void display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

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
    display(head);
    int choice=1;
    while(choice){
        printf("\nWhat operation you want to perform:\n1. Insertion at beginning\n2. Insertion at end \n3. Insertion at position\n4. Deletion at beginning\n5. Deletion at end\n6. Deletion at position\n7. Reverse the linked list\n");
        int operation, num;
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("Enter element to be inserted: ");
            newnode=(struct node*)malloc(sizeof(struct node*));
            scanf("%d", &newnode->data);
            newnode->next=head;
            head=newnode;
            display(head);
            break;
        
        case 2:
            newnode=(struct node*)malloc(sizeof(struct node*));
            printf("Enter element to be inserted: ");
            scanf("%d", &newnode->data);
            newnode->next=0;
            temp=head;
            while(temp->next!=0){
                temp=temp->next;
            }
            temp->next=newnode;
            display(head);

        default:
            break;
        }
        
        printf("\nWant to perform any other operations?(Yes-1/No-0) ");
        scanf("%d", &choice);
    }
    
    
    return 0;
 }
 