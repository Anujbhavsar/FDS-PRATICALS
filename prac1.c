/*
Assignment Title: Write a program to implement stack using array
Name: Sakshi Date
Roll No-16
Batch-S1
Academic Year: 2026-2027

Program code:
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

bool push(int);
void pop(void);
void display(void);

int stack[SIZE];
int top = -1;

int main(void) {
    int value;
    int choice;

    while (1) {
        printf("*****MENU*****\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted into stack:\n");
                scanf("%d", &value);
                if (!push(value)) {
                    printf("Failed to push: Stack Overflow\n");
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
}

bool push(int value) {
    if (top >= SIZE - 1) {
        return false;
    }
    stack[++top] = value;
    printf("Insertion successful\n");
    return true;
}

void pop(void) {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

void display(void) {
    if (top < 0) {
        printf("Stack Underflow\n");
    } else {
        printf("Displaying stack elements:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d\n", stack[i]);
        }
    }
}

/*
OUTPUT:

student@BTECH-PROJECTLAB-76:~/sakshidate$ gcc prac1.c
student@BTECH-PROJECTLAB-76:~/sakshidate$ ./a.out
*****MENU*****
1.PUSH
2.POP
3.DISPLAY
4.EXIT
1
Enter the value to be inserted into stack:
20
Insertion successful
*/
