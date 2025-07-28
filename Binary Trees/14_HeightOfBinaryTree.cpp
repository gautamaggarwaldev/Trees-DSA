#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int cal(Node *node)
    {
        if (node == NULL)
            return 0;
        return 1 + max(cal(node->left), cal(node->right));
    }
    int height(Node *node)
    {
        int ans = cal(node);
        return ans - 1;
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
    cout << "Height of Binary Tree: " << sol.height(a) << endl;
}