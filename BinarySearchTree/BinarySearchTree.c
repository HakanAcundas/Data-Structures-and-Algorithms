#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root;

struct Node* GetNewNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* Insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(struct Node* root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (root->data <= data)
        return Search(root->left, data);
    else
        return Search(root->left, data);
}

int main()
{
    root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 22);
    root = Insert(root, 7);
    printf("%d", Search(root, 7));
    printf("%d", Search(root, 31));
    return 0;
}
