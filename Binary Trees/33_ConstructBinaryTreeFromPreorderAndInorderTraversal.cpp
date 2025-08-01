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
    int findPos(vector<int> &in, int ele, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == ele)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> &pre, vector<int> &in, int inStartIdx, int inEndIdx, int &preIdx, int n)
    {
        if (preIdx >= n || inStartIdx > inEndIdx)
        {
            return NULL;
        }
        int ele = pre[preIdx++]; // Get the current element from preorder
        TreeNode *root = new TreeNode(ele); // Create a new TreeNode with the current element
        int pos = findPos(in, ele, n); // Find the position of the current element in inorder traversal

        root->left = solve(pre, in, inStartIdx, pos - 1, preIdx, n); // Recursively build the left subtree
        root->right = solve(pre, in, pos + 1, inEndIdx, preIdx, n); // Recursively build the right subtree
        return root;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        int n = pre.size();
        int preIdx = 0; // Index for preorder traversal
        TreeNode *ans = solve(pre, in, 0, n - 1, preIdx, n);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = sol.buildTree(preorder, inorder);
    
    return 0;
}