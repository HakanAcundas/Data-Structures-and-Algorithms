#include <iostream>
#include <queue>
#include <math.h>

// BinarySearchTree
template <typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;

    Node() : data(T()), left(nullptr), right(nullptr) {}
    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
Node<T>* Insert(Node<T>* root, T value)
{
    if (root == nullptr) 
    {   
        root = new Node<T>;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    else if (value <= root->data)
    {
        root->left = Insert(root->left, value);
    }
    else
    {
        root->right = Insert(root->right, value);
    }

    return root;
}

template <typename T>
bool Search(Node<T>* root, T value)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (value == root->data)
    {
        return true;
    }
    else if (value <= root->data)
    {
        Search(root->left, value);
    }
    else 
    {
        Search(root->right, value);
    }
    return false;
}

template <typename T>
void BreadthFirstSearch(Node<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<Node<T>*> q;
    q.push(root);

    while(!q.empty())
    {
        Node<T>* current = q.front();
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
    std::cout << "\n";
}

template <typename T>
void DepthFirstSearch(Node<T>* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout<< root->data << " ";
    DepthFirstSearch(root->left);
    DepthFirstSearch(root->right);
}

template <typename T>
T Max(Node<T>* root)
{
    int max;
    if (root == nullptr)
    {
        std::cout << "ERROR: Empty tree!!!\n";
    }
    Node<T> current = *root;
    while (current.right != NULL)
    {
        current = *current.right;
    }

    return current.data;
}

template <typename T>
T Min(Node<T>* root)
{
    int max;
    if (root == nullptr)
    {
        std::cout << "ERROR: Empty tree!!!\n";
    }
    Node<T> current = *root;
    while (current.left != NULL)
    {
        current = *current.left;
    }

    return current.data;
}

template <typename T>
int FindTreeHeight(Node<T>* root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int leftHeight = FindTreeHeight(root->left);
    int rightHeight = FindTreeHeight(root->right);

    return std::max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node<int> root;
    Insert(&root, 3);
    std::cout << Search(&root, 5) << "\n";
    std::cout << Search(&root, 3) << "\n";

    Insert(&root, -1);
    Insert(&root, 5);
    Insert(&root, 8);
    Insert(&root, -2);
    BreadthFirstSearch(&root);
    DepthFirstSearch(&root);

    Insert(&root, 101);
    std::cout << "\n" << Max(&root) << "\n";
    Insert(&root, -77);
    std::cout << Min(&root) << "\n";

    std::cout << FindTreeHeight(&root) << "\n";
    return 0;
}
