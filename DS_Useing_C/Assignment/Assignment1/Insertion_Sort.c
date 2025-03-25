#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int*, int);
int main() {
    int n, i;
    int *a;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int)); 
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter data to the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    printf("Display the array data:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");

    insertion_sort(a, n);

    printf("Display the sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");

    free(a);
    return 0;
}

void insertion_sort(int *p, int x) {
    int i, j, temp;
    for (i = 1; i < x; i++) { 
        temp = p[i];
        j = i - 1;

        while (j >= 0 && p[j] > temp) { 
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = temp;
    }
}
