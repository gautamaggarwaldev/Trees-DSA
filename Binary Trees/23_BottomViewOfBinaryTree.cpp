#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            Node *temp = f.first;
            int hd = f.second;

            mp[hd] = temp->data; //do not check any condition just update the map with the current node's value

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
};
int main()
{
    Node *root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->right = new Node{6, nullptr, nullptr};

    Solution sol;
    vector<int> bottomView = sol.bottomView(root);
    
    for (int val : bottomView)
    {
        cout << val << " ";
    }
    
    return 0;
}