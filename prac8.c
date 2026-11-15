/*
Assignment Name: Linked Lists
Student Name: Pranav Ukade
Roll No.: 61
Batch: S4
Academic Year: 2026-2027



*/#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node* createNode(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));


    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;


    return newNode;
}


struct node* insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);


    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);


    return root;
}


void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main()
{
    struct node *root = NULL;


    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    int i;


    for (i = 0; i < n; i++)
    {
        root = insert(root, values[i]);
    }


    printf("Inorder Traversal of BST: ");
    inorder(root);


    return 0;
}

Output

Inorder Traversal of BST: 20 30 40 50 60 70 80
