#include <stdio.h>
#include <stdlib.h>

// Define the tree node structure
typedef struct nodetype {
    int info;
    struct nodetype *left, *right;
} tree;

// Recursive function to create the tree with user input
void create_tree(tree *ptr, int item) {
    char ch;
    int newr, newl;

    if (ptr != NULL) {
        // Set the value for the current node
        ptr->info = item;

        // Ask if left subtree exists
        printf("Does node %d have a left child? (y/n): ", item);
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y') {
            tree *lptr = (tree *)malloc(sizeof(tree));  // Allocate memory for left child
            printf("Enter value for left child of %d: ", ptr->info);
            scanf("%d", &newl);
            ptr->left = lptr;
            create_tree(lptr, newl);  // Recursively create left subtree
        } else {
            ptr->left = NULL;  // No left child
        }

        // Ask if right subtree exists
        printf("Does node %d have a right child? (y/n): ", item);
        scanf(" %c", &ch);
        if (ch == 'y' || ch == 'Y') {
            tree *rptr = (tree *)malloc(sizeof(tree));  // Allocate memory for right child
            printf("Enter value for right child of %d: ", ptr->info);
            scanf("%d", &newr);
            ptr->right = rptr;
            create_tree(rptr, newr);  // Recursively create right subtree
        } else {
            ptr->right = NULL;  // No right child
        }
    }
}

// Preorder traversal: Root -> Left -> Right
void preorder(tree *root) {
    if (root != NULL) {
        printf("%d  ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d  ", root->info);
        inorder(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void postorder(tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->info);
    }
}

int main() {
    tree *root;
    int rootVal;

    // Ask the user for the root node value (IMPROVED)
    printf("Enter the value of the root node: ");
    scanf("%d", &rootVal);

    // Allocate memory for root node and create tree
    root = (tree *)malloc(sizeof(tree));
    create_tree(root, rootVal);

    // Display tree traversals
    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\nPostorder traversal:\n");
    postorder(root);

    printf("\nInorder traversal:\n");
    inorder(root);

    return 0;
}
