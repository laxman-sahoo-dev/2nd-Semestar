#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef, exp;
    struct node *next;
} Poly;

// Function declarations
Poly* create();
void display(Poly *poly);
Poly* add(Poly *p1, Poly *p2);

// Main function
int main() {
    Poly *p1, *p2, *sum;

    printf("Enter first polynomial:\n");
    p1 = create();

    printf("Enter second polynomial:\n");
    p2 = create();

    printf("First Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    sum = add(p1, p2);
    printf("Sum of polynomials: ");
    display(sum);

    return 0;
}

// Create polynomial list
Poly* create() {
    Poly *head = NULL, *tail = NULL;
    char choice;

    do {
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
        printf("Enter coefficient: ");
        scanf("%d", &newNode->coef);
        printf("Enter exponent: ");
        scanf("%d", &newNode->exp);
        newNode->next = NULL;

        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Add more terms? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return head;
}

// Display the polynomial
void display(Poly *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->exp);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
Poly* add(Poly *p1, Poly *p2) {
    Poly *sum = NULL, *tail = NULL;

    while (p1 != NULL && p2 != NULL) {
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
        newNode->next = NULL;

        if (p1->exp == p2->exp) {
            newNode->coef = p1->coef + p2->coef;
            newNode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            newNode->coef = p1->coef;
            newNode->exp = p1->exp;
            p1 = p1->next;
        } else {
            newNode->coef = p2->coef;
            newNode->exp = p2->exp;
            p2 = p2->next;
        }

        if (sum == NULL)
            sum = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
        newNode->coef = p1->coef;
        newNode->exp = p1->exp;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        Poly *newNode = (Poly *)malloc(sizeof(Poly));
        newNode->coef = p2->coef;
        newNode->exp = p2->exp;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        p2 = p2->next;
    }

    return sum;
}
