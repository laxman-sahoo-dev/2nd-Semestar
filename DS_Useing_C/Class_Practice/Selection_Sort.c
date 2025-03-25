#include<stdio.h>
#include<stdlib.h>
void selection_sort(int*,int);
int main(){
int i, n, *p;
printf("Enter the range of the array:");
scanf("%d",&n);
p=(int*)malloc(n*sizeof(int));
printf("\nEnter data to the array: ");
for(i=0;i<n;i++)
    {
    scanf("%d",p+i);
    }
printf("\nDisplay the array element:\n");
for(i=0;i<n;i++)
    {
    printf("%d  ",*(p+i));
    }
selection_sort(p,n);
printf("\n\nDisplay the sorted array:\n");
for(i=0;i<n;i++){
    printf("%d ",*(p+i));
}
}
void selection_sort(int *a, int n){
int min,i,j,temp;
for(i=0;i<n-1;i++)
    {
    min=i;
    for(j=i+1;j<n;j++) 
        {
        if(a[j]<a[min])
            {
            min=j;
            }
        }
    if(min!=i)
        {
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        }      
    }
}
