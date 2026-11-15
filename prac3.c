/*
Assignment Title: practical 3
Name: Sakshi Date
Roll number:
Batch:S2
Academic year:2026-2027

program code;
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

bool push(char);
char pop( );
int prec(char);
void infixTopostfix(char*);

char stack[SIZE];
int top= -1;

int main() {
  char infix[SIZE];
  printf("Enter the infix expression:\n");
  scanf("%s",infix);

 infixTopostfix(infix);

return 0;

}

bool push(char value) {
  if(top>= SIZE-1){
  printf("Stack Overflow\n");
  return false;
  }  else {
    top=top + 1;
    stack[top]=value;
return true;
  }

}

char pop(){
  if(top<0){
  printf("stack underflow\n");
  return '\0';
  } else {
   char value = stack[top];
   top = top-1;
   return value;
   }
 }  

int  prec(char c)
{
   if(c == '/' ||c == '*')
   {
     return 2;
    }
    else if(c =='+'|| c == '-')
   {
   return 1;
    }
   else 
   {
   return -1;
   }
  }
 
 void infixTopostfix(char*s){
 char result[SIZE];
 int resultIndex=0;
 int len = strlen(s);
 
 for(int i=0; i<len; i++) {
 char c = s[i];
 
     if((c>='a' && c<='z')|| ( c>='A' && c<='Z') || ( c>= '1' && c<='9')){
      result[resultIndex++] =c;
 }
    else if (c=='(') {
       push (c);
  }
  
  else if (c == ')') {
       while (top >= 0 && stack [top] != '(') {
        result[resultIndex++] = pop();
      
      }
      pop(); //pop'('
     
  }
  
  else{
       while (top >= 0 && stack [top] != '(' &&
            (prec(c) < prec(stack[top]) ||
            (prec(c) == prec(stack[top]))
            )
            ) {
          result[resultIndex++] = pop();
         }
         push(c);
        }
    }
    
    //pop all the remaining elements from the stack
    while (top >= 0) {
         result[resultIndex++] = pop();
      
      }
      
      result[resultIndex] = '\0';
      printf("postfix expression: %s\n" , result);
  }


/*
OUTPUT: 
student@BTECH-PROJECTLAB-76:~/sakshidate$ gcc prac3.c
student@BTECH-PROJECTLAB-76:~/sakshidate$ ./a.out
Enter the infix expression:
a+b*c-(d+e/f)*g
postfix expression: abc*+def/+g*-
*/
