#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void bubble_sort(int *, int);
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
    bubble_sort(a, n);
    printf("Display after sorting- ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", *(a + i));
    }
}
void bubble_sort(int *arr, int n)
{
    int i, j,temp;
    for (i = 0; i < n; i++)
    {
        bool flag=false;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                bool flag=true;
            }
        }
        if(flag==false)
        {
            break;
        }
    }
}