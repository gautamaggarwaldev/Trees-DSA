#include <iostream>
#include <algorithm>
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
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(Node *root)
    {
        if (root == NULL)
            return 0;
        int ls = diameterOfBinaryTree(root->left);
        int rs = diameterOfBinaryTree(root->right);
        int LsRs = height(root->left) + height(root->right);
        return max({ls, rs, LsRs});
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
    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(a) << endl;
}