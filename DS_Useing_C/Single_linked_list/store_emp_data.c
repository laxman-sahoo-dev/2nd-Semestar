#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30
typedef struct single_linked_list
{
    int data;
    char name[max];
    char dep[max];
    struct single_linked_list *next;
} sll;
sll *traverse(sll *node)
{
    sll *prev;
    while (node != NULL)
    {
        prev = node;
        node = node->next;
    }
    return prev;
}
void create_sll(sll **list1, int val, char *str1, char *str2)
{
    sll *curr, *last = NULL;
    curr = (sll *)malloc(sizeof(sll));
    curr->data = val;
    strcpy(curr->name, str1);
    strcpy(curr->dep, str2);
    curr->next = NULL;
    if ((*list1) == NULL)
    {
        (*list1) = curr;
    }
    else
    {
        last = traverse(*list1);
        last->next = curr;
    }
}
void display_list(sll *list)
{
    while (list!=NULL)
    {
        /* code */
        printf("NAME-%s\tDEPARTMENT-%s\tROOL NO- %d\n",list->name,list->dep,list->data);
        list=list->next;
    }
    
}
int main()
{   
    sll *list=NULL;
    char str1[max], str2[max];
    char ch;
    int data;
    do
    {
        printf("Enter Roll- ");
        scanf("%d",&data);
        getchar();
        printf("Enter NAME- ");
        fgets(str1, sizeof(str1), stdin);
        if (str1[strlen(str1) - 1] == '\n')
        {
            str1[strlen(str1) - 1] = '\0';
        }
        printf("Enter DEPARTMENT-");
        fgets(str2, sizeof(str2), stdin);
        if (str2[strlen(str2) - 1] == '\n')
        {
            str2[strlen(str2) - 1] = '\0';
        }
        create_sll(&list,data,str1,str2);
        printf("Do you Want to create another node- ");
        scanf(" %c",&ch);
    } while (ch=='y'|| ch=='Y');
    printf("Display=\n");
    display_list(list);
}