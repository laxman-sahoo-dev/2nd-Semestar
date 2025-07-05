#include <stdio.h>
#include <stdlib.h>
typedef struct search_delete
{
        int data;
        struct search_delete *next;
}sll;
sll *first=NULL,*last;
void search_delete(sll *f,int s);
void display(sll*);
int main(){
        char ch;
        int info,s;
        do{

                sll *curr=NULL;
                curr=(sll*)malloc(sizeof(sll));
                printf("Enter Data- ");
                scanf("%d",&info);
                getchar();
                curr->data=info;
                curr->next=NULL;
                if(first==NULL){
                        first=last=curr;
                }
                else{
                        last->next=curr;
                        last=curr;
                }
                fflush(stdin);
                printf("Do you want to continue: ");
                scanf("%c",&ch);
        }while(ch=='y'||ch=='Y');
        display(first);
        printf("Which  element do you want to delete = ");
        fflush(stdin);
        scanf("%d",&s);
        printf("Display after deletion -\n" );
        search_delete(first,s);
        display(first);
}
void search_delete(sll *f,int s){
        sll *temp=f,*temp1,*temp2=NULL;
        while(temp!=NULL){
                if(s==temp->next->data){
                        printf("\nFOUND\n");
                        temp1=temp;
                        temp2=temp->next->next;
                        temp1->next=temp2;
                }
                temp=temp->next;
        }
}
void display(sll *node){
        while(node!=NULL){
                printf("%d -> ",node->data);
                node=node->next;
        }
        printf("NULL\n");
}