#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void lot(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        queue<TreeNode *> q;
        bool flag = true;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> levels;
            for (int i = 0; i < s; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                levels.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            if (flag)
            {
                ans.push_back(levels);
            }
            else
            {
                reverse(levels.begin(), levels.end());
                ans.push_back(levels);
            }
            flag = !flag;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        lot(root, ans);
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

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(a);

    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}