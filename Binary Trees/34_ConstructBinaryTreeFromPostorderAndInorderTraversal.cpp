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
    void mapping(map<int, int> &mp, vector<int> &in, int n) // Function to map inorder elements with their indices
    {
        for (int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
    }
    TreeNode *solve(vector<int> &in, vector<int> &post, int inStartIdx, int inEndIdx, int &postIdx, int n, map<int, int> &mp)
    {
        if (postIdx < 0 || inStartIdx > inEndIdx)
            return NULL;

        int ele = post[postIdx--]; // Get the current element from postorder
        TreeNode *root = new TreeNode(ele); // Create a new TreeNode with the current element
        int pos = mp[ele]; // Find the index of the current element in inorder using the map

        // Postorder traversal visits left, right, then root, so we need to construct the right subtree first
        root->right = solve(in, post, pos + 1, inEndIdx, postIdx, n, mp);
        root->left = solve(in, post, inStartIdx, pos - 1, postIdx, n, mp);
        return root;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &post)
    {
        int n = in.size();
        map<int, int> mp;
        mapping(mp, in, n);
        int postIdx = n - 1; // Index for postorder traversal
        TreeNode *ans = solve(in, post, 0, n - 1, postIdx, n, mp);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = sol.buildTree(inorder, postorder);


}