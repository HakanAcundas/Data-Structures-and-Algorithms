#include <iostream>
#include <queue>

struct Node
{
    char data;
    Node *left;
    Node *right;
};

// TODO: Implement Insert, Pop etc for node struct

void BreadthFirstSearch(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* current = q.front();
        std::cout<< current->data << " ";

         // Add children of current Node to queue
        if (current->left != NULL)
        {
            q.push(current->left);
        }
         if (current->right != NULL)
        {
            q.push(current->right);
        }
        // Remove current Node from queue
        q.pop();
    }
}

void DepthFirstSearch(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    std::cout<< root->data << " ";
    DepthFirstSearch(root->left);
    DepthFirstSearch(root->right);
}

int main()
{
    return 0;
}