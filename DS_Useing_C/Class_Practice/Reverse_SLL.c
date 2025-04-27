#include <stdlib.h>
#include <stdio.h>
typedef struct single_linked_list{
    int data;
    struct single_linked_list *next;
}sll;
sll* Reverse_list(sll*);
sll *first=NULL , *last ,*curr;
int main() {
    int n,i;
    sll *node;
    printf("Enter how many node do you want to creat: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        curr=(sll*)malloc(sizeof(sll));
        printf("Enter the data for(%d) node - ",i+1);
        scanf("%d",&curr->data);
        curr->next=NULL;
        if(first==NULL){
            first=curr;
            node=first;
        }
        else{
            last->next=curr;
        }
        last=curr;
    }
    printf("Display the linked list element :\n ");
    while(node!=NULL){
        printf("%d -> ",node->data);
        node=node->next;
    }
       printf("NULL\n");
    printf("Display the list in reverse order: \n ");
    node = Reverse_list(first);
    while(node!=NULL){
        printf("%d -> ",node->data);
        node=node->next;
    }
    printf("NULL\n");
    return 0;
}
sll* Reverse_list(sll* x){
    sll *p1,*p2,*p3;
    p1=x;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL){
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    x=p2;
    return x;
}
