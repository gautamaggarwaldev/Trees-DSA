#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution
{
public:
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
            return {0, 0};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;
        res.first = root->data + left.second + right.second; // Include current node's value and the values of non-adjacent nodes from left and right subtrees
        res.second = max(left.first, left.second) + max(right.first, right.second); // Take the maximum of including or excluding the left and right subtrees
        return res;
    }
    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};
int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);
    Node *g = new Node(70);

    a->right = c;
    a->left = b;
    b->right = e;
    b->left = d;
    c->right = g;
    c->left = f;

    Solution sol;
    int maxSum = sol.getMaxSum(a);
    cout << "Maximum Sum of Non-Adjacent Nodes: " << maxSum << endl;

    return 0;
}