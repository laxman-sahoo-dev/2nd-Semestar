
#include <stdio.h>
#include <stdlib.h>
typedef struct double_link_list{
    struct double_link_list *prev;
    int data;
    struct double_link_list *next;
}dll;
dll *first=NULL,*last,*curr;
void create_dll(int);
void display_dll_forward(dll *node);
void display_dll_backward(dll *node);
int main() {
    int n,num,i;
    printf("Enter the no node do you want to creat: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter data:");
        scanf("%d",&num);
        create_dll(num);
    }
    printf("Display the linked list data in forward direction = \n");
    display_dll_forward(first);
    printf("Display the linked list data in backward direction=\n");
    display_dll_backward(last);
    return 0;
}
void create_dll(int num){
    curr=(dll*)malloc(sizeof(dll));
    if(curr==NULL){
        printf("Memory allocation is failed\n");
        exit(1);
    }
    curr->prev=NULL;
    curr->data=num;
    curr->next=NULL;
    if(first==NULL){
        first=curr;
    }
    else{
        curr->prev=last;
        last->next=curr;
    }
    last=curr;
}
void display_dll_forward(dll *fd){
    while(fd!=NULL){
        printf("%d -> ",fd->data);
        fd=fd->next;
    }
    printf("NULL\n");
}
void display_dll_backward(dll *bd){
    while(bd!=NULL){
        printf("%d -> ",bd->data);
        bd=bd->prev;
    }
    printf("NULL\n");
}
