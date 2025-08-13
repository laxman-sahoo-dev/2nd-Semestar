#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct Node {
    Person data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node* createNode(Person p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertFront(Person p) {
    Node* newNode = createNode(p);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(Person p) {
    Node* newNode = createNode(p);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = front;
    printf("Deleted from front: %s, Age: %d\n", temp->data.name, temp->data.age);
    front = front->next;
    if (front) front->prev = NULL;
    else rear = NULL;
    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = rear;
    printf("Deleted from rear: %s, Age: %d\n", temp->data.name, temp->data.age);
    rear = rear->prev;
    if (rear) rear->next = NULL;
    else front = NULL;
    free(temp);
}

void display() {
    Node* temp = front;
    printf("Deque:\n");
    while (temp) {
        printf("Name: %s, Age: %d\n", temp->data.name, temp->data.age);
        temp = temp->next;
    }
}

int main() {
    Person p1 = {"Alice", 25};
    Person p2 = {"Bob", 30};
    Person p3 = {"Charlie", 22};

    insertRear(p1);
    insertFront(p2);
    insertRear(p3);
    display();

    deleteFront();
    deleteRear();
    display();

    return 0;
}
