#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
    TreeNode *parentToNodeMapping(TreeNode *root, map<TreeNode *, TreeNode *> &mp1, int start) 
    // Function to map parent nodes to their children
    {
        TreeNode *res = NULL;
        queue<TreeNode *> q;
        q.push(root);
        mp1[root] = NULL;
        while (!q.empty())
        {
            TreeNode *f = q.front();
            q.pop();
            if (f->val == start)
            {
                res = f; // If the current node is the target node, store it
            }
            if (f->left)
            {
                mp1[f->left] = f;
                q.push(f->left);
            }
            if (f->right)
            {
                mp1[f->right] = f;
                q.push(f->right);
            }
        }
        return res;
    }
    int burnTree(TreeNode *target, map<TreeNode *, TreeNode *> &mp1)
    {
        map<TreeNode *, bool> visited; // To keep track of visited nodes
        queue<TreeNode *> q; // Queue to perform BFS
        int ans = 0;
        visited[target] = 1;
        q.push(target);
        while (!q.empty())
        {
            bool flag = 0; // Flag to check if any new node is burned in this level
            int s = q.size();
            while (s--) // Process all nodes at the current level
            {
                TreeNode *f = q.front();
                q.pop();
                if (f->left && !visited[f->left]) // Check left child 
                {
                    flag = 1;
                    q.push(f->left);
                    visited[f->left] = 1;
                }
                if (f->right && !visited[f->right]) // Check right child
                {
                    flag = 1;
                    q.push(f->right);
                    visited[f->right] = 1;
                }
                if (mp1[f] && !visited[mp1[f]]) // Check parent node
                {
                    flag = 1;
                    q.push(mp1[f]);
                    visited[mp1[f]] = 1;
                }
            }
            if (flag) ans++; // If any new node was burned in this level, increment the time
        }
        return ans;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        map<TreeNode *, TreeNode *> mp1;
        TreeNode *target = parentToNodeMapping(root, mp1, start);
        int ans = burnTree(target, mp1);
        return ans;
    }
};
int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    int start = 2; 
    int result = sol.amountOfTime(root, start);
    cout << "Minimum time to burn the entire binary tree: " << result << endl;

    return 0;
}