#include <stdio.h>
#include <stdlib.h>

// Define structure for Circular Singly Linked List node
typedef struct single_linked_list
{
    int data;
    struct single_linked_list *next;
} cll;

// Function to find and return the last node of a circular linked list
cll *traverse_cll(cll *list)
{
    if (list == NULL)
        return NULL;

    cll *temp = list;
    // Traverse until we find the last node (whose next points to head)
    while (temp->next != list)
    {
        temp = temp->next;
    }
    return temp; // Return the last node
}

// Function to display the circular linked list
void display_cll(cll *list1)
{
    if (list1 == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    cll *temp = list1;
    // Loop until we circle back to the head
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list1);
    printf("NULL\n");
}

// Function to create a new node and add it to the circular linked list
void create(cll **list1)
{
    int item;
    cll *node1 = NULL;
    cll *last = NULL;

    printf("Please enter the data- ");
    scanf("%d", &item);

    node1 = (cll *)malloc(sizeof(cll));
    if (node1 == NULL)
    {
        printf("\nNode creation failed");
        exit(0);
    }

    node1->data = item;
    node1->next = NULL;

    if (*list1 == NULL) // If list is empty, initialize it
    {
        *list1 = node1;
        node1->next = *list1; // Points to itself
    }
    else
    {
        last = traverse_cll(*list1);
        last->next = node1;
        node1->next = *list1;
    }
}

// Function to delete a node with given data (sdata) from the list
void delete_element(cll **list1, int sdata)
{
    cll *temp = *list1, *last = traverse_cll(*list1), *prev = NULL;

    if (temp == NULL)
        return;

    // Deleting head node
    if (temp->data == sdata)
    {
        if (temp->next == temp) // Only one node in list
        {
            free(temp);
            *list1 = NULL;
            return;
        }
        *list1 = temp->next;
        last->next = *list1;
        free(temp);
        return;
    }

    // Traverse to find the node to delete
    do
    {
        prev = temp;
        temp = temp->next;
    } while (temp != *list1 && temp->data != sdata);

    // If element not found
    if (temp == *list1)
    {
        printf("Search element is not found\n");
        return;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);
}

// Function to insert a node at a given position (1-based index)
void insert(cll **list1, int po)
{
    cll *curr = NULL, *last = traverse_cll(*list1), *temp = *list1, *prev = NULL;
    int count;

    curr = (cll *)malloc(sizeof(cll));
    printf("Enter data: ");
    scanf("%d", &curr->data);
    curr->next = NULL;

    if (*list1 == NULL) // Empty list
    {
        curr->next = curr;
        *list1 = curr;
        return;
    }

    // Insert at beginning
    if (po == 1)
    {
        last->next = curr;
        curr->next = temp;
        *list1 = curr;
        return;
    }

    // Traverse to the position
    count = 1;
    do
    {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != *list1 && count < po);

    if (po == count)
    {
        prev->next = curr;
        curr->next = temp;
    }
    else
    {
        printf("Invalid position.\n");
        free(curr);
    }
}

// Function to delete a node at a given position (1-based index)
void delete(cll **list1, int po)
{
    int count = 1;
    cll *last = traverse_cll(*list1), *temp = *list1, *prev;

    if (*list1 == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    // Deleting the first node
    if (po == 1)
    {
        if (temp->next == temp)
        {
            free(temp);
            *list1 = NULL;
            return;
        }
        last->next = temp->next;
        *list1 = temp->next;
        free(temp);
        return;
    }

    // Traverse to the position
    do
    {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != *list1 && count != po);

    if (po == count)
    {
        prev->next = temp->next;
        free(temp);
    }
    else
    {
        printf("Invalid position.\n");
    }
}

// Function to free all nodes in the list
void free_list(cll *list)
{
    if (list == NULL)
        return;

    cll *temp = list, *fre;
    do
    {
        fre = temp;
        temp = temp->next;
        free(fre);
    } while (temp != list);
}

// Main function to drive menu-based circular linked list operations
int main()
{
    cll *list = NULL;
    int choice, val, po, num;

    printf("\n\tMENU\t\n");
    printf("_________________\n");
    printf("1- Insert\n2- Delete a given number\n3- Display\n4- Insert at position\n5- Delete at position\n6- Exit\n");

    while (1)
    {
        printf("Enter a choice- ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create(&list);
            break;
        case 2:
            printf("Enter the element to delete- ");
            scanf("%d", &num);
            delete_element(&list, num);
            break;
        case 3:
            printf("Display-\n");
            display_cll(list);
            break;
        case 4:
            printf("Enter the position to insert- ");
            scanf("%d", &po);
            insert(&list, po);
            break;
        case 5:
            printf("Enter the position to delete- ");
            scanf("%d", &po);
            delete(&list, po);
            break;
        case 6:
            free_list(list);
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
