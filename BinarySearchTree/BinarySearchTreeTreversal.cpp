#include <iostream>
#include <queue>

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

int main()
{
    Node<int>* root = nullptr;
    root = Insert(root, 3);
    std::cout << Search(root, 5) << "\n";
    std::cout << Search(root, 3) << "\n";

    root = Insert(root, -1);
    root = Insert(root, 5);
    root = Insert(root, 8);
    root = Insert(root, -2);
    BreadthFirstSearch(root);
    DepthFirstSearch(root);
    return 0;
}
