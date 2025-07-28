#include <iostream>
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
    int height(Node *root)
    {
        return root == NULL ? 0 : 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(Node *root)
    {
        if (root == NULL)
            return true;
        int l = height(root->left);
        int r = height(root->right);
        int diff = abs(l - r);
        if (diff > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
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
    cout << "Is the Binary Tree Balanced? " << (sol.isBalanced(a) ? "Yes" : "No") << endl;

    return 0;
}