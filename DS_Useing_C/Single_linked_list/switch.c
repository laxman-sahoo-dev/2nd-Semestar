#include <stdio.h>
#include <stdlib.h> 

// Definition of a node in the singly linked list
typedef struct single_linked_list
{
    int data;
    struct single_linked_list *next;
} sll;

// Function to traverse the list and return the last node
sll *traverse_sll(sll *node)
{
    sll *prev = NULL;
    while (node != NULL)
    {
        prev = node;
        node = node->next;
    }
    return prev;
}

// Function to create (append) a new node with a given value at the end of the list
void create(sll **list1, int val)
{
    sll *curr = NULL, *last;

    // Allocate memory for the new node
    curr = (sll *)malloc(sizeof(sll));
    curr->data = val;
    curr->next = NULL;

    // If list is empty, set head to the new node
    if ((*list1) == NULL)
    {
        (*list1) = curr;
    }
    else
    {
        // Otherwise, find the last node and append the new node
        last = traverse_sll(*list1);
        last->next = curr;
    }
}

// Function to print the entire list
void display(sll *node)
{
    while (node)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n"); // Indicates end of list
}

// Function to delete the first node containing the given value
void delete_element(sll **list, int num)
{
    sll *temp = (*list), *prev = NULL;

    // ⚠ Ensure list is not empty
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    // If head node contains the value
    if (temp->data == num)
    {
        (*list) = temp->next;  // Update head
        free(temp);           // Free the old head
    }
    else
    {
        // Traverse list to find the node with matching value
        while (temp != NULL && temp->data != num)
        {
            prev = temp;
            temp = temp->next;
        }

        // ⚠ Check if element was not found
        if (temp == NULL) {
            printf("Element not found\n");
            return;
        }

        // Bypass and delete the node
        prev->next = temp->next;
        free(temp);
    }
}

// Function to delete node at a specific position (1-based index)
void delete(sll **list2, int po)
{
    sll *prev = NULL, *temp = (*list2);

    // ⚠ Ensure list is not empty
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    if (po == 1)
    {
        (*list2) = temp->next;
        free(temp); // Free the old head
    }
    else
    {   
        int count = 1;

        // Traverse to the desired position
        while (count != po && temp != NULL)
        {
            prev = temp;
            count = count + 1;
            temp = temp->next;
        }

        // ⚠ Check if position was out of bounds
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }

        // Delete the node
        prev->next = temp->next;
        free(temp);
    }
}

// Function to insert a new node at a given position (1-based index)
void insert(sll **list1, int po)
{
    sll *temp = (*list1), *curr = NULL, *prev;
    int num;

    // Allocate new node
    curr = (sll *)malloc(sizeof(sll));
    printf("Enter the insert value- ");
    scanf("%d", &num);
    curr->data = num;
    curr->next = NULL;

    // Insert at head
    if (po == 1)
    {
        curr->next = temp;
        (*list1) = curr;
        return;
    }
    else
    {
        int i = 1;

        // Traverse to the target position
        while (po != i && temp != NULL)
        {
            prev = temp;
            i = i + 1;
            temp = temp->next;
        }

        // ⚠ If position is valid
        if (po == i)
        {
            curr->next = temp;
            prev->next = curr;
        }
        else
        {
            // ⚠ Invalid position
            printf("Position out of range\n");
            free(curr); // Prevent memory leak
        }
    }
}

// Function to free all nodes in the list (used at program exit)
void free_list(sll *head) {
    sll *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main menu-driven program
int main()
{
    sll *list = NULL;
    int choice, val, po, num;

    // Print the menu
    printf("\n\tMENU\t\n");
    printf("_________________\n");
    printf("1 - Insert at end\n");
    printf("2 - Delete a given number\n");
    printf("3 - Display\n");
    printf("4 - Insert at position\n");
    printf("5 - Delete at position\n");
    printf("6 - Exit\n");

    while (1)
    {
        printf("Enter a choice- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value- ");
            scanf("%d", &val);
            create(&list, val); // Insert at end
            break;

        case 2:
            printf("Enter the element to delete- ");
            scanf("%d", &num);
            delete_element(&list, num); // Delete by value
            break;

        case 3:
            printf("Display-\n");
            display(list); // Display list
            break;

        case 4:
            printf("Enter the position to insert- ");
            scanf("%d", &po);
            insert(&list, po); // Insert at position
            break;

        case 5:
            printf("Delete data enter any position- ");
            scanf("%d", &po);
            delete(&list, po); // Delete at position
            break;

        case 6:
            free_list(list); // Clean up memory
            printf("Exiting program. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice\n"); // Catch invalid menu option
            break;
        }
    }
}
