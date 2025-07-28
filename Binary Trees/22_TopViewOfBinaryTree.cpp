#include <iostream>
#include <vector>
#include <queue>
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
vector<int> getTopView(TreeNode *root)
{
    vector<int> ans;
    map<int, int> mp;               // hd,nodeValue
    queue<pair<TreeNode *, int>> q; // node, hd
    if (root == NULL)
    {
        return ans;
    }
    q.push({root, 0});
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        TreeNode *temp = f.first;
        int hd = f.second;

        if (mp.find(hd) == mp.end()) // if horizontal distance is not present in map, then insert it
        {
            mp[hd] = temp->val; // insert the node value at that horizontal distance
        }
        if (temp->left)
        {
            q.push({temp->left, hd - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, hd + 1});
        }
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
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

    vector<int> topView = getTopView(a);
    cout << "Top View of Binary Tree: ";
    for (int val : topView)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}