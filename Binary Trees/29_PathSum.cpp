#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    bool solve(TreeNode *root, int ts)
    {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
        {
            return ts == root->val;
        }
        bool leftAns = solve(root->left, ts - root->val);
        bool rightAns = solve(root->right, ts - root->val);
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode *root, int ts)
    {
        return solve(root, ts);
    }
};
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;
    bool result = sol.hasPathSum(root, targetSum);
    
    cout << (result ? "True" : "False") << endl;
    
    return 0;
}