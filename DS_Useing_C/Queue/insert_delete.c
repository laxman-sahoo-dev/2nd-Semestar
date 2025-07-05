#include <stdio.h>
#define max 5
//Data structure for linear queue
typedef struct lquetype
{
    int arr[max];
    int front,rear;
}lqueue;
 //function to initialise Linear queue

 void init_LQ(lqueue *q)
 {
    q->front=q->rear=-1;
 }

 //fuction to check queue Empty

 void isempty_LQ(lqueue *lq)
 {
    if(lq->front==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
 }
 
