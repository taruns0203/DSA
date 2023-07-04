#include <iostream>
#include <queue>
#include <map>
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

void printLeftTree(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    // left
    printLeftTree(root->left, ans, level + 1);

    // right
    printLeftTree(root->right, ans, level + 1);
}

int main()
{
    Node *root = NULL;
    root = buildTree();
    vector<int> ans;
    int level = 0;

    // printBottomView(root);

    printLeftTree(root, ans, level);

    cout << "Printing the left View: " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

// input - 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1
// output - Printing the left View:
// 10 20 30 60