#include <iostream>
#include <vector>
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
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void leftPartTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        ans.push_back(root->data);
        if (root->left)
        {
            leftPartTraversal(root->left, ans);
        }
        else
        {
            leftPartTraversal(root->right, ans);
        }
    }
    void leafNodeTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
        }
        leafNodeTraversal(root->left, ans);
        leafNodeTraversal(root->right, ans);
    }
    void rightPartTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
        {
            rightPartTraversal(root->right, ans);
        }
        else
            rightPartTraversal(root->left, ans);

        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        ans.push_back(root->data);

        // left part side
        leftPartTraversal(root->left, ans);

        // leaf nodes
        leafNodeTraversal(root->left, ans);
        leafNodeTraversal(root->right, ans);

        // right part side
        rightPartTraversal(root->right, ans);
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
    vector<int> result = sol.boundaryTraversal(a);

    cout << "Boundary Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}