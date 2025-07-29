#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    vector<int> diagonal(TreeNode *root)
    {
        vector<int> ans;
        map<int, vector<int>> mp;
        queue<pair<TreeNode *, int>> q;
        if (root == NULL)
            return ans;
        q.push({root, 0});
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            TreeNode *temp = f.first;
            int hd = f.second;
            mp[hd].push_back(temp->data);
            if (temp->left)
            {
                q.push({temp->left, hd + 1});
            }
            if (temp->right)
            {
                q.push({temp->right, hd});
            }
        }
        for (auto i : mp)
        {
            for (int x : i.second)
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
int main()
{
    
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    TreeNode *g = new TreeNode(7);

    a->right = c;
    a->left = b;
    b->right = e;
    b->left = d;
    c->right = g;
    c->left = f;

    Solution sol;
    vector<int> diagonalTraversal = sol.diagonal(a);
    for (int val : diagonalTraversal)
    {
        cout << val << " ";
    }
}