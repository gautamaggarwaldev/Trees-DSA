#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void leftsideView(Node *root, vector<int> &ans, int level)
    {
        if (root == NULL)
            return;

        // enter into new level
        if (level == ans.size())
        {
            ans.push_back(root->data);
        }
        leftsideView(root->right, ans, level + 1);
        leftsideView(root->left, ans, level + 1);
    }
    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        leftsideView(root, ans, 0);
        return ans;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution sol;
    vector<int> leftView = sol.leftView(root);
    for (int val : leftView)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
