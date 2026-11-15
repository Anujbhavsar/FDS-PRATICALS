/* 
Assignment Title: Write a program for evaluation of postfix expression
Name: Sakshi Date
Roll No.16
Batch:S1
Academic year: 2026-2027
program code;


*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 10

bool push(int);
int pop(void);
int evaluatePostfix(char*);

int stack[SIZE];
int top = -1;
int main() {
    char postfix[SIZE];
    
    printf("enter the postfix expression:\n");
    scanf("%s", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);
    
    return 0;
}

bool push(int value) {
     if (top >= SIZE - 1){
        return false;
        } else {
        top = top + 1;
        stack[top] = value;
        return true;
      }
  }
  
  int pop() {
     if (top < 0) {
         printf("stack underflow\n");
         return -1;
         } else {
               int value = stack[top];
               top =top - 1;
               return value;
               
        }
  }
int evaluatePostfix(char* postfix){
  for (int i = 0; postfix[i]!= '\0'; i++){
    if(isdigit(postfix[i])) {
       push(postfix[i] - '0');
    } else {
         int val2 = pop();
         int val1 = pop();
         switch (postfix[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': if(val2==0)
                        { 
                        printf("val2 is zero, so division is not possible");
                        break;
                        }else push(val1 / val2);
                        break;
              }
          }
      }
      return pop();
}


/*
OUTPUT:

student@BTECH-PROJECTLAB-76:~/sakshidate$ gcc prac2.c
student@BTECH-PROJECTLAB-76:~/sakshidate$ ./a.out
enter the postfix expression:
12+  
The result of the postfix expression is: 3
*/
