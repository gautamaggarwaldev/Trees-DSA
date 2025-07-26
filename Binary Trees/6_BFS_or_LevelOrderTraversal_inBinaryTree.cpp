#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    void levelsOrder(Node *root, vector<vector<int>> &ans)
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> levels;
            for (int i = 0; i < s; i++)
            {
                Node *temp = q.front();
                q.pop();
                levels.push_back(temp->data);

                if (temp->left)
                {
                    q.push({temp->left});
                }
                if (temp->right)
                {
                    q.push({temp->right});
                }
            }
            ans.push_back(levels);
        }
    }
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        levelsOrder(root, ans);
        return ans;
    }
};
int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);

    a->right = c;
    a->left = b;
    b->right = e;
    b->left = d;
    c->right = g;
    c->left = f;

    Solution sol;
    vector<vector<int>> ans = sol.levelOrder(a);

    cout << "Level Order Traversal in Binary Tree: " << endl;
    for (const auto &level : ans)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}