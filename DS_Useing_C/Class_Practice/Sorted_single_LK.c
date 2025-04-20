#include <stdio.h>
#include <stdlib.h>

typedef struct single_link_list {
    int data;
    struct single_link_list *next;
} sll;

void create_sorted_sll(sll **list1) {
    sll *node = (sll*)malloc(sizeof(sll));
    int item;

    if (!node) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &item);
    node->data = item;
    node->next = NULL;

    // Empty list or insert at beginning
    if (*list1 == NULL || item < (*list1)->data) {
        node->next = *list1;
        *list1 = node;
        return;
    }

    sll *prev = NULL;
    sll *curr = *list1;

    while (curr != NULL && curr->data <= item) {
        prev = curr;
        curr = curr->next;
    }

    // Insert in between or at the end
    node->next = curr;
    prev->next = node;
}

void display(sll* list) {
    printf("Display the sorted list:\n");
    while (list != NULL) {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main() {
    sll *list = NULL;
    char ch;

    do {
        create_sorted_sll(&list);
        printf("Do you want to create another node? (y/n): ");
        getchar();
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');

    display(list);
    return 0;
}
