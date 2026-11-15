/*
Assignment Title: Write a program to sort an array using insertion sort
Name: pranav ukade
Roll No-61
Batch-S4
Academic Year: 2026-2027

Program code:

*/
#include <stdio.h>

void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int n = 7;
    int arr[7] = {15, 6, 9, 21, 36, 2, 5};

    printf("Original array: ");
    displayArray(arr, n);

    insertionsort(arr, n);

    printf("Sorted array: ");
    displayArray(arr, n);

    return 0;
}




/*
OUTPUT:  

student@BTECH-PROJECTLAB-88:~/pranav uakde SECSD 61$ gcc prac5.c
student@BTECH-PROJECTLAB-88:~/pranav uakde SECSD 61$ ./a.out
Original array: 15 6 9 21 36 2 5 
Sorted array: 2 5 6 9 15 21 36 
*/
