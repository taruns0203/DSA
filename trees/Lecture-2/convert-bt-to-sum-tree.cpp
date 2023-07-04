
struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree

    int solve(Node *node)
    {
        // Your code here

        if (node == NULL)
        {
            return 0;
        }

        int leftAns = solve(node->left);
        int rightAns = solve(node->right);
        int x = node->data;
        node->data = leftAns + rightAns;
        return leftAns + x + rightAns;
    }
    void toSumTree(Node *node)
    {

        solve(node);
        // return node->data;
    }
};