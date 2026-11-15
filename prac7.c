/*
Assignment Title: Implement a stack using a linked list
Name: Pranav Ukade
Roll number:61
Batch:S4
Academic year:2026-2027

program code;
*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push() {
    int value;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

void pop() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void isEmpty() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
}

void display() {
    struct Node *temp = top;

    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Stack Using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    while (top != NULL) {
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}

/*             
 OUTPUT:
    student@BTECH-PROJECTLAB-88:~/pranav ukade SECSD 61$ gcc prac7.c
student@BTECH-PROJECTLAB-88:~/pranav ukade SECSD 61$ ./a.out

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 1
Enter value to push: 10
10 pushed into stack.

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 1
Enter value to push: 20
20 pushed into stack.

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 5
Stack elements (Top to Bottom): 20 -> 10 -> NULL

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 3
Top element: 20

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 2
Popped element: 20

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 5
Stack elements (Top to Bottom): 10 -> NULL

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 4
Stack is not empty.

--- Stack Using Linked List ---
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 6
Exiting program.
*/
