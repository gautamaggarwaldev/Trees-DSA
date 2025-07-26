#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int solveMax(Node *root)
    {
        if (root == NULL)
            return INT_MIN;
        int x = max(root->data, max(solveMax(root->left), solveMax(root->right)));
        return x;
    }
    int solveMin(Node *root)
    {
        if (root == NULL)
            return INT_MAX;
        int y = min(root->data, min(solveMin(root->left), solveMin(root->right)));
        return y;
    }
    int findMax(Node *root)
    {
        int maxVal = solveMax(root);
        return maxVal;
    }

    int findMin(Node *root)
    {
        int minVal = solveMin(root);
        return minVal;
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
    cout << "Maximum Value in Binary Tree: " << sol.findMax(a) << endl;
    cout << "Minimum Value in Binary Tree: " << sol.findMin(a) << endl;

    return 0;
}