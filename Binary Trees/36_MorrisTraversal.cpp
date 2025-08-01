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
    vector<int> morris(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *curr = root; // Start with the root node
        while (curr != NULL)
        {
            if (curr->left != NULL) // If there is a left child
            {
                TreeNode *pred = curr->left; // Find the inorder predecessor
                while (pred->right != NULL && pred->right != curr) // Traverse to the rightmost node of the left subtree
                {
                    pred = pred->right; // Move to the right child
                }
                if (pred->right == NULL) // If the right child is NULL, we set it to the current node
                {
                    pred->right = curr; // Create a temporary link to the current node
                    curr = curr->left; // Move to the left child
                }
                if (pred->right == curr) // If the right child is already set to the current node
                {
                    pred->right = NULL; // Remove the temporary link
                    ans.push_back(curr->val); // Add the current node's value to the result
                    curr = curr->right; // Move to the right child
                }
            }
            else
            {
                ans.push_back(curr->val); // If there is no left child, add the current node's value to the result
                curr = curr->right; // Move to the right child 
            }
        }
        return ans;
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
    vector<int> result = sol.morris(root);

    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}