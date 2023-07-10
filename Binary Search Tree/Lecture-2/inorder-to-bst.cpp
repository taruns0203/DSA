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
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // A
        Node *temp = q.front();
        // B
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // C
            cout << temp->data << " ";
            // D
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *bstUsingInOrder(int inorder[], int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    // find middle
    int mid = (s + e) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    root->left = bstUsingInOrder(inorder, s, mid - 1);
    root->right = bstUsingInOrder(inorder, mid + 1, e);

    return root;
}
int main()
{
    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;

    Node *root = bstUsingInOrder(inorder, s, e);
    levelOrderTraversal(root);

    return 0;
}

// 1:50 for deleteBST