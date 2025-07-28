#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    bool isSameTree(Node *p, Node *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool value = p->val == q->val;
        if (left && right && value)
            return true;
        else
            return false;
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

    Node *x = new Node(1);
    Node *y = new Node(2);
    Node *z = new Node(3);
    x->right = y;
    x->left = z;

    Solution sol;
    cout << "Are the two trees identical? " << (sol.isSameTree(a, x) ? "Yes" : "No") << endl;

    return 0;
}