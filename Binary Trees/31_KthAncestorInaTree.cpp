#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

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
    Node *solve(Node *root, int &k, int node)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == node)
        {
            return root;
        }
        Node *l = solve(root->left, k, node);
        Node *r = solve(root->right, k, node);

        if (l != NULL && r == NULL)
        {
            k--;
            if (k <= 0)
            {
                k = INT_MAX; // Reset k to INT_MAX to indicate that we found the kth ancestor
                return root; // Return the current node as the kth ancestor
            }
            return l;
        }
        if (l == NULL && r != NULL)
        {
            k--;
            if (k <= 0)
            {
                k = INT_MAX;
                return root;
            }
            return r;
        }
        return NULL;
    }
    int kthAncestor(Node *root, int k, int node)
    {
        Node *ans = solve(root, k, node);
        if (ans == NULL || ans->data == node) // If the node is not found or if the node itself is the ancestor
        {
            return -1;
        }
        return ans->data;
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
    int k = 2; // Kth ancestor
    int node = 5; // Node for which we want to find the Kth ancestor
    int result = sol.kthAncestor(root, k, node);

    cout << "Kth Ancestor of node " << node << " is: " << result << endl;

    return 0;
}