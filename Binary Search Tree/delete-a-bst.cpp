
#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int maxVal(TreeNode *root)
    {
        TreeNode *temp = root;
        if (temp == NULL)
        {
            return -1;
        }

        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->val;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // base case
        if (root == NULL)
        {
            return NULL;
        }

        if (root->val == key)
        {
            // isi ko delete krna
            // 4 cases
            if (root->left == NULL && root->right == NULL)
            {
                // leaf Node
                delete root;
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                TreeNode *child = root->right;
                delete root;
                return child;
            }
            else if (root->left != NULL && root->right == NULL)
            {
                TreeNode *child = root->left;
                delete root;
                return child;
            }
            else
            {
                // both child
                // find inorder predeccessor in left subtree
                int inorderPre = maxVal(root->left);
                // replace root->data value with inorder predeccessor
                root->val = inorderPre;
                // delete inorder predeccessor from left subtree
                root->left = deleteNode(root->left, inorderPre);
                return root;
            }
        }

        else if (key > root->val)
        {
            // right jana chahiy
            root->right = deleteNode(root->right, key);
        }

        else if (key < root->val)
        {
            // left jana chahiy
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};