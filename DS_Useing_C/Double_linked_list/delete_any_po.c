#include <stdio.h>
#include <stdlib.h>

// Define the doubly circular linked list node
typedef struct double_linked_list {
    struct double_linked_list *prev;
    int data;
    struct double_linked_list *next;
} dll;

// Function to insert a node at the end
void insert_end(dll **head, dll **tail, int data) {
    dll *new_node = (dll *)malloc(sizeof(dll));
    new_node->data = data;

    if (*head == NULL) {
        new_node->next = new_node->prev = new_node;
        *head = *tail = new_node;
    } else {
        new_node->prev = *tail;
        new_node->next = *head;
        (*tail)->next = new_node;
        (*head)->prev = new_node;
        *tail = new_node;
    }
}

// Function to display list forward
void display_forward(dll *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    dll *temp = head;
    printf("Forward: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to display list backward
void display_backward(dll *tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    dll *temp = tail;
    printf("Backward: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("(tail)\n");
}

// Function to delete a node at a given position
void delete_at_position(dll **head, dll **tail, int pos) {
    if (*head == NULL || pos < 1) {
        printf("List is empty or invalid position.\n");
        return;
    }

    dll *temp = *head;
    dll *prev = NULL;
    int count = 1;

    // Special case: only one node
    if (*head == *tail && pos == 1) {
        free(temp);
        *head = *tail = NULL;
        return;
    }

    // Deleting head node
    if (pos == 1) {
        *head = temp->next;
        (*head)->prev = *tail;
        (*tail)->next = *head;
        free(temp);
        return;
    }

    // Traverse to the node to be deleted
    while (count < pos && temp != *tail) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // If position is valid
    if (count == pos) {
        prev->next = temp->next;
        temp->next->prev = prev;

        if (temp == *tail)
            *tail = prev;

        free(temp);
    } else {
        printf("Invalid position.\n");
    }
}

// Main function
int main() {
    dll *head = NULL, *tail = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at end\n");
        printf("2. Delete at position\n");
        printf("3. Display forward\n");
        printf("4. Display backward\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_end(&head, &tail, data);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at_position(&head, &tail, pos);
                break;
            case 3:
                display_forward(head);
                break;
            case 4:
                display_backward(tail);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
