#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> mp; // map<hd, map<levels,nodes>>>mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        if (root == NULL)
            return ans;
        q.push({root, {0, 0}}); //{horizontal {dist, levels}}
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            TreeNode *frontNode = f.first;
            int hd = f.second.first;
            int lvls = f.second.second;

            mp[hd][lvls].push_back(frontNode->val);
            if (frontNode->left)
            {
                q.push({frontNode->left, {hd - 1, lvls + 1}});
            }
            if (frontNode->right)
            {
                q.push({frontNode->right, {hd + 1, lvls + 1}});
            }
        }

        for (auto &[hd, levels] : mp)
        {
            vector<int> col;
            for (auto &[level, nodes] : levels)
            {
                // nodes ---> containing values at a specific horizontal distance and level in the tree.
                sort(nodes.begin(), nodes.end()); // sort nodes at same position
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(col);
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
    vector<vector<int>> result = sol.verticalTraversal(a);

    cout << "Vertical Traversal of Binary Tree:" << endl;
    for (const auto &col : result)
    {
        for (int val : col)
        {
            cout << "[" <<  val << "]";
        }
        cout << ", ";
    }

    return 0;
}