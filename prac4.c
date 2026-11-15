/*
Assignment Title: write a program to implement circular queue using an array
Name:Sakshi Date
Roll no.16
Batch:S1
Academic year:2026-2027

Program code:
*/

#include<stdio.h>

#define SIZE 4

int queue[SIZE];
int frontindex = -1, rearindex = -2;

int isQueueFull(){
    if((rearindex + 1)% SIZE == frontindex)
       return 1;
       
       return 0;
       }
int isQueueEmpty(){
    if(frontindex == -1)
    return 1;
    return 0;
    }
    
void enqueue(int element){
   if(isQueueFull())
     printf("Queue is Full\n");
     else{
        if(frontindex == -1)
          frontindex = 0;
        rearindex =(rearindex + 1)% SIZE;
        queue[rearindex] = element;
        printf("inserted--->%d",element);
        }
      }
int dequeue(){
  int element;
  if(isQueueEmpty()){
   printf("Queue is Empty!\n");
   return -1;
  }else{
   element = queue[frontindex];
   if(frontindex == rearindex){
      frontindex = -1;
      rearindex = -1;
      
    }else{
      frontindex = (frontindex + 1)%SIZE;
      }
      printf("Deleted element-->%d\n",element);
      return element;
      }
    }
    
void displayQueue(){
    if(isQueueEmpty()){
    printf("Queue is Empty\n");
    return;
    }
    printf("Elements in circular Queue are:\n");
     int i = frontindex;
     while(1){
        printf("%d\n",queue[i]);
        if(i == rearindex)
        break;
      i = (i + 1)%SIZE;
      }
    }
    
int main(){
  int userChoice;
  int element;
  
   while(1){
       printf("Circular Queue Menu:\n");
       printf("1.Enqueue\n");
       printf("2.Dequeue\n");
       printf("3.Display\n");
       printf("4.Exit\n");
       printf("Enter your choice:");
       scanf("%d",&userChoice);
       
       switch(userChoice){
         case 1:
               printf("Enter element to enqueue:");
               scanf("%d",&element);
               enqueue(element);
               break;
         case 2:
               dequeue();
               break;
         case 3:
               displayQueue();
               break;
         case 4:
               printf("Existing the program.\n");
               return 0;
            default:
               printf("Invalid choice. Please try again.\n");
               }
            }
        }
        
              
 /*             
 OUTPUT:
          student@BTECH-PROJECTLAB-76:~/sakshidate$ gcc prac4.c
student@BTECH-PROJECTLAB-76:~/sakshidate$ ./a.out
Circular Queue Menu:
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice:1
Enter element to enqueue:10
Queue is Full
Circular Queue Menu:
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice:2
Queue is Empty!
Circular Queue Menu:
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter your choice:4
Existing the program.
*/
