#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}sll; 
sll *top=NULL;

void push(int val){
    sll *curr=NULL;
    curr=(sll*)malloc(sizeof(sll));
    if(curr==NULL){
        printf("Momoery allocation is failed ");
        return;
    }
    curr->data=val;
    curr->next=top;
    top=curr;
}
void pop(){
    sll *temp=NULL;
    temp=top;
    if(top==NULL){
        printf("stack is underflow");
    }
    top=top->next;
    free(temp);
}
void display(){
    sll *node;
    node=top;
    if(top==NULL){
        printf("stack is empty");
    }
    while(node!=NULL){
        printf(" %d -> ",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");  
        
        }
    }
    return 0;
} 