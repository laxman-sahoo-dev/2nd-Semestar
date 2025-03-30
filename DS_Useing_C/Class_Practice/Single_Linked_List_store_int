#include<stdio.h>
#include<stdlib.h>
typedef struct SingleLinkList{
    int data;
    struct SingleLinkList *next;
}sll;
void CreatList(int);
void DisplayList(sll*);
sll *first=NULL,*curr,*last;
int main(){
    char ch;
    int num;
    printf("Do you want to create a node? (y/n): ");
    scanf(" %c", &ch);
    while(ch=='y'||ch=='Y')
    {
         printf("Enter a Number:");
         scanf("%d",&num);
         getchar();
         CreatList(num);
         printf("Do you want to creat another Node-");
         scanf("%c",&ch);
    }
    DisplayList(first);
}
void CreatList(int num){
    curr=(sll*)malloc(sizeof(sll));
    if(curr==NULL)
    {
        printf("Unsuccessful Allocation");
        exit (1);
    }
    curr->data=num;
    curr->next=NULL;
    if(first==NULL)
    {
        first=curr;        
    }
    else
    {
        last->next=curr;
    }
    last=curr;
}
void DisplayList(sll* node)
{   
    if(node==NULL){
        printf("List is empty.\n");
        return;
    }
    printf("Linked List Element are=\n");
    while(node!=NULL)
    {
        printf("%d\n",node->data);
        node=node->next;
    }
}
