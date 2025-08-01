#include <iostream>
#include <vector>
#include <map>
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
    void mapping(vector<int> &in, map<int, int> &mp, int n) // Function to map inorder elements with their indices
    {
        for (int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
    }
    TreeNode *solve(vector<int> &pre, vector<int> &in, int inStartIdx, int inEndIdx, int &preIdx, int n, map<int, int> &mp)
    {
        if (preIdx >= n || inStartIdx > inEndIdx)
        {
            return NULL;
        }
        int ele = pre[preIdx++]; // Get the current element from preorder
        TreeNode *root = new TreeNode(ele); // Create a new TreeNode with the current element
        int pos = mp[ele]; // Find the index of the current element in inorder using the map

        root->left = solve(pre, in, inStartIdx, pos - 1, preIdx, n, mp);
        root->right = solve(pre, in, pos + 1, inEndIdx, preIdx, n, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        int n = pre.size();
        map<int, int> mp; // map inorder element with their index
        mapping(in, mp, n);
        int preIdx = 0; // Index for preorder traversal
        TreeNode *ans = solve(pre, in, 0, n - 1, preIdx, n, mp);
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