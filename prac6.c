/*
Assignment Title: Singly linked list with insertion at the beginning and end
Name: pranav ukade 
Roll number:61
Batch:S4
Academic year:2026-2027

program code;
*/

// singly linked list 
#include <stdio.h> 
#include <stdlib.h> 

struct Node {
int data;
struct Node* next;
};
 
 
 struct Node* creatNode(int data ) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
  
  }
  
  struct Node* insertATbeginning(struct Node* head, int data ) { 
      struct Node* newNode = creatNode(data);
      newNode->next = head;
      return newNode;
       }
       
       struct Node* insertAtEnd(struct Node* head, int data ) { 
       struct Node* newNode = creatNode(data);
      if (head ==NULL ) {
      return newNode;
       }
       
        struct Node* temp = head;
       while (temp->next !=NULL) 
         temp = temp->next;
        temp->next = newNode;
        //return head;
  } 
  
    
    
    void displaylist (struct Node* head) {
    if( head == NULL) {
    printf("List is empty.\n"); 
      return;
       }
       
       struct Node* temp = head;
       while (temp != NULL) {
         printf("%d -> ", temp->data);
         temp = temp->next;
         }
         printf("NULL\n");
         }
         
         int main() {
         struct Node* head=NULL;
          int choice, value;
          
          while (1) {
           printf("\nmenu:\n");
           printf("1. insert at beginning\n");
           printf("2. insert at end\n");
           printf("3. Display list\n");
           printf("4. Exit\n");
           printf("Enter your choice: ");
           scanf("%d" , &choice);
  
            switch (choice) {
                case 1:
                   printf("Enter the value to insert at beginning: ");
                  scanf("%d" , &value);
                  head = insertATbeginning (head, value);
                  break;
               
               case 2:
               printf("Enter the value to insert at end: ");
                  scanf("%d" , &value);
                  head = insertAtEnd(head, value);
                  break;
               
               case 3:
               printf("Linked List: ");
                  displaylist(head);
                 break;
              
               case 4:
                exit(0);
                break;
                default:
                printf("Invalid choice, please try again.\n");
                }
                }
                return 0;
                }
            
 /*             
 OUTPUT:
    student@BTECH-PROJECTLAB-88:~/pranav uakde SECSD 61$ gcc prac6.c
student@BTECH-PROJECTLAB-88:~/pranav uakde SECSD 61$ ./a.out

menu:
1. insert at beginning
2. insert at end
3. Display list
4. Exit
Enter your choice: 1
Enter the value to insert at beginning: 2

menu:
1. insert at beginning
2. insert at end
3. Display list
4. Exit
Enter your choice: 3
Linked List: 2 -> NULL

menu:
1. insert at beginning
2. insert at end
3. Display list
4. Exit
Enter your choice: 2
Enter the value to insert at end: 80

menu:
1. insert at beginning
2. insert at end
3. Display list
4. Exit
Enter your choice: 3
Linked List: 2 -> 80 -> NULL

menu:
1. insert at beginning
2. insert at end
3. Display list
4. Exit
Enter your choice: 4
student@BTECH-PROJECTLAB-88:~/pranav uakde SECSD 61$ ^C
student@BTECH-PROJECTLAB-88:~/pranav uakde SECSD 61$ A
*/
