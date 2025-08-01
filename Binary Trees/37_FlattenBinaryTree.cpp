#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left)
            {
                TreeNode *pred = curr->left;
                while (pred->right)
                {
                    pred = pred->right;
                }
                pred->right = curr->right; // Link the right subtree
                curr->right = curr->left; // Move the left subtree to the right
                curr->left = NULL; // Set the left child to NULL
            }
            curr = curr->right; // Move to the right child
        }
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    sol.flatten(root);

    // Print the flattened tree
    TreeNode *curr = root;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}