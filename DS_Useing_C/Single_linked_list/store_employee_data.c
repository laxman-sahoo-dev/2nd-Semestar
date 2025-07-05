#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct employee_sll{
        int roll;
        char name[20];
        char dep[20];
        struct employee_sll *link;
}emp;
emp *f=NULL,*c,*l;
void create(int,char[],char[]);
void display(emp*);
int main(){
        char ch,str[20],str2[20];
        int roll;
        do{
                printf("\nEnter ROLL= ");
                scanf("%d",&roll);
                getchar();
                printf("\nEnter NAME= ");
                fgets(str,sizeof(str),stdin);
                if(str[strlen(str)-1]=='\n')
                {
                        str[strlen(str)-1]='\0';
                }
                printf("\nEnter DEPARTMENT= ");
                fgets(str2,sizeof(str2),stdin);
                if(str[strlen(str2)-1]=='\n')
                {
                        str[strlen(str2)-1]='\0';
                }
                create(roll,str,str2);
                fflush(stdin);
                printf("\nDo you want to continue= ");
                scanf("%c",&ch);
        }while(ch=='y'||ch=='Y');
        display(f);
}
void create(int r,char str1[],char str2 []){
        c=(emp*)malloc(sizeof(emp));
        if(c==NULL){
                printf("Memory allocation is fialed");
                exit(0);
        }
        c->roll=r;
        strcpy(c->name,str1);
        strcpy(c->dep,str2);
        c->link=NULL;
        if(f==NULL){
                f=c;
        }
        else{
                l->link=c;
        }
        l=c;
}
void display(emp* node){
        while(node!=NULL)
        {
                printf("ROLL= %d\t",node->roll);
                printf("NAME= %s\t",node->name);
                printf("DEPARTMENT= %s\n\n",node->dep);
                node=node->link;
        }

}