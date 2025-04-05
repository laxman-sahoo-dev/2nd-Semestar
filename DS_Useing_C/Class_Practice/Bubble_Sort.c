#include <stdio.h>
#include <stdlib.h>

int i,j;
void bubble_sort(int* a,int n)
{
   int temp;
   for(i=0;i<n;i++){
       for(j=0;j<n-i-1;j++){
           //checking the adjacent element & move the larger element at last of the array
           if(a[j]>a[j+1]){
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
   }
}
int main() {
    int *p=NULL;
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    printf("Enter data to the array: ");
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    printf("Display the array element: \n");
    for(i=0;i<n;i++){
        printf("%d\n",*(p+i));
    }
    bubble_sort(p,n);
    printf("Display the sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d\n",*(p+i));
    }
    return 0;
}
