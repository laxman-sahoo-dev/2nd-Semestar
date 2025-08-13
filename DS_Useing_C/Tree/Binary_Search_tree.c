#include <stdio.h>
#include <stdlib.h>

typedef struct Binary_Search_tree
{
    int info;
    struct Binary_Search_tree *left, *righ;
} tree;
tree *create_tree(int val)
{
    tree *node = (tree *)malloc(sizeof(tree));
    node->info = val;
    node->righ = NULL;
    node->left = NULL;
    return node;
}
tree *insert_binary_tree(tree *root, int val)
{
    if (root == NULL)
    {
        return create_tree(val);
    }
    if (val < root->info)
    {
        root->left = insert_binary_tree(root->left, val);
    }
    else
    {
        root->righ = insert_binary_tree(root->righ, val);
    }
    return root;
}

void preorder(tree* root)
{
    if(root!=NULL)
    {
        printf("%d  ",root->info);
        preorder(root->left);
        preorder(root->righ);
    }
}

tree* search(tree *roof,int data)
{
    if(roof->info==data || roof==NULL)
    {
        return roof;
    }
    else if(data < roof->info)
    {
        return search(roof->left,data);
    }
    else
    {
        return search(roof->righ,data);
    }
}

int main()
{
    int data,sd,n;
    char ch;
    tree *root=NULL,*snode;
    printf("How many node do you want to create- ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data for node %d- ",i+1);
        scanf("%d",&data);
        root=insert_binary_tree(root,data);
    }
   /* do
    {
        printf("Enter the data -");
        scanf("%d", &data);
        root=insert_binary_tree(root,data);
        printf("Do you want to create another node- ");
        scanf(" %c",&ch);

    }while(ch=='y'||ch=='Y');*/
    printf("Display:\n");
    preorder(root);
    printf("Enter which data you want to search- ");
    scanf("%d",&sd);
    snode= search(root,data);
    if(snode->info==data)
    {
        printf("\nData is found!!\n");
    }
    else{
        printf("Not found!!\n");
    }

}