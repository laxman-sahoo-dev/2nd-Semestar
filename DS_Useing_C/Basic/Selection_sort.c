#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void selection_sort(int *, int);
int main()
{
    int *a, n, i;
    printf("Enteer the range- ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter array element- ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    selection_sort(a, n);
    printf("Display after sorting- ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", *(a + i));
    }
}
void selection_sort(int *arr,int n)
{
    int min,i,j;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}