#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;

    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    // Step A, B, C
    Node *root = new Node(data);

    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

void inorderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // NLR
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // LRN

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    root = buildTree();

    levelOrderTraversal(root);

    return 0;
}
