#include <stdio.h>
#include <stdlib.h>

int stack[5];
int top = -1;
void main(){
    int ch;
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                if(top == 4){
                    printf("Stack Overflow\n");
                } else {
                    int value;
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                }
                break;
            case 2:
                if(top == -1){
                    printf("Stack Underflow\n");
                } else {
                    printf("Popped value: %d\n", stack[top]);
                    top--;
                }
                break;
            case 3:
                if(top == -1){
                    printf("Stack is empty\n");
                } else {
                    printf("Stack elements: ");
                    for(int i = 0; i <= top; i++){
                        printf("%d ", stack[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}