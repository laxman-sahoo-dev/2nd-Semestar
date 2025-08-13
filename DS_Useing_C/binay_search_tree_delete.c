#include <stdio.h>
#include <stdlib.h>

typedef struct Binary_Search_tree {
    int info;
    struct Binary_Search_tree *left, *righ;
} tree;

tree *create_tree(int val) {
    tree *node = (tree *)malloc(sizeof(tree));
    node->info = val;
    node->left = NULL;
    node->righ = NULL;
    return node;
}

tree *insert_binary_tree(tree *root, int val) {
    if (root == NULL)
        return create_tree(val);

    if (val < root->info)
        root->left = insert_binary_tree(root->left, val);
    else
        root->righ = insert_binary_tree(root->righ, val);

    return root;
}

void preorder(tree *root) {
    if (root != NULL) {
        printf("%d  ", root->info);
        preorder(root->left);
        preorder(root->righ);
    }
}

tree *search(tree *roof, int data) {
    if (roof == NULL || roof->info == data)
        return roof;

    if (data < roof->info)
        return search(roof->left, data);
    else
        return search(roof->righ, data);
}

// Helper to find minimum value node (used for deleting a node with 2 children)
tree* find_min(tree* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST
tree* delete_node(tree* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->info)
        root->left = delete_node(root->left, key);
    else if (key > root->info)
        root->righ = delete_node(root->righ, key);
    else {
        // Case 1 & 2: Node with one child or no child
        if (root->left == NULL) {
            tree* temp = root->righ;
            free(root);
            return temp;
        } else if (root->righ == NULL) {
            tree* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        tree* temp = find_min(root->righ); // Find inorder successor
        root->info = temp->info; // Copy value
        root->righ = delete_node(root->righ, temp->info); // Delete successor
    }

    return root;
}

// Free the entire tree (optional cleanup)
void delete_tree(tree *root) {
    if (root == NULL)
        return;
    delete_tree(root->left);
    delete_tree(root->righ);
    free(root);
}

int main() {
    int data, sd, del, n;
    tree *root = NULL, *snode;

    printf("How many nodes do you want to create? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insert_binary_tree(root, data);
    }

    printf("\nBST Preorder Traversal:\n");
    preorder(root);

    printf("\n\nEnter data to search: ");
    scanf("%d", &sd);
    snode = search(root, sd);
    if (snode != NULL) {
        printf("Data found: %d\n", snode->info);
    } else {
        printf("Data not found!\n");
    }

    printf("\nEnter data to delete from BST: ");
    scanf("%d", &del);
    root = delete_node(root, del);

    printf("\nBST after deletion (Preorder):\n");
    preorder(root);

    // Optional: free memory
    delete_tree(root);
    return 0;
}
