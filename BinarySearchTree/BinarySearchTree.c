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

int GetMax(struct Node* root)
{
    int max = 0;
    if (root != NULL)
    {
        struct Node* current = root;
        while(current->right != NULL)
        {
            current = current->right;
        }
        return current->data;
    }
    else
    {
        printf("ERROR: Tree is empty!!!\n");
        return -1;
    }
    
    return max;
}

int GetMin(struct Node* root)
{
    if (root != NULL)
    {
        struct Node* current = root;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current->data;
    }
    else
    {
        printf("ERROR: Tree is empty!!!\n");
        return -1;
    }
}

// The height of a tree is the number of edges in the longest path from the root to a leaf node.
GetHeight(struct Node* root)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if (root != NULL)
    {
        leftHeight = GetHeight(root->left);
        rightHeight = GetHeight(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
    else
    {
        printf("ERROR: Tree is empty!!!\n");
        return -1;
    }
}

int main()
{
    root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 22);
    root = Insert(root, 7);
    printf("%d\n", Search(root, 7));
    printf("%d\n", Search(root, 31));
    printf("%d\n", GetMax(root));
    root = Insert(root, -7);
    printf("%d\n", GetMin(root));

    root = Insert(root, -9);
    root = Insert(root, -11);
    root = Insert(root, -12);
    printf("%d\n", GetHeight(root));
    return 0;
}
