
#include <stdio.h>
#include <stdlib.h>

typedef struct merge_link_list{
    int data;
    struct merge_link_list *next;
}mll;
void create(mll*);
void merge(mll*,mll*,mll*);
void display(mll*);

int main() {
    mll *node1,*node2,*node3;
    node1=(mll*)malloc(sizeof(mll));
    if(node1==NULL){
        printf("Out of memory space!");
        exit(1);
    }
    node2=(mll*)malloc(sizeof(mll));
    if(node2==NULL){
        printf("Out of memory space!!");
        exit(1);
    }
    node3=(mll*)malloc(sizeof(mll));
    if(node3==NULL){
        printf("Out of memory space !!!");
        exit(1);
    }
    create(node1);
    create(node2);
    merge (node1,node2,node3);
    printf("Display the node1=\n");
    display(node1);
    printf("Display the node2=\n");
    display(node2);
    printf("Display after merge node1&node2= \n");
    display(node3);
    return 0;
}
void create(mll *node){
    char ch;
    printf("Enter the value for first node- ");
    scanf("%d",&node->data);
    node->next=NULL;
    printf("Do you want to enter another value(Y/N)=");
    while ((ch = getchar()) != '\n' && ch != EOF);
    ch=getchar();
    while(ch=='y'||ch=='Y'){
        node->next=(mll*)malloc(sizeof(mll));
        if(node->next==NULL){
            printf("Out of memory space..");
        }
        node=node->next;
        printf("Enter value for another node= ");
        scanf("%d",&node->data);
        node->next=NULL;
        printf("Do you want to continue:(Y/N) ");
        while ((ch = getchar()) != '\n' && ch != EOF);
        ch=getchar();
    }
}
void merge(mll *n1,mll *n2,mll *n3){
    n3->data=n1->data;
    n3->next=NULL;
    n1=n1->next;
    while(n1!=NULL){
        n3->next=(mll*)malloc(sizeof(mll));
        n3=n3->next;
        n3->data=n1->data;
        n1=n1->next;
        n3->next=NULL;
    }
    while(n2!=NULL){
        n3->next=(mll*)malloc(sizeof(mll));
        n3=n3->next;
        n3->data=n2->data;
        n2=n2->next;
        n3->next=NULL;
    }
}
void display(mll *node){
    while(node!=NULL){
        printf("%d -> ",node->data);
        node=node->next;
    }
    printf("NULL\n");
}
