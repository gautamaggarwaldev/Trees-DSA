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
    void inorder(Node *root, vector<Node *> &in)
    {
        if (root == NULL)
            return;
        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }
    Node *flattenBST(Node *root)
    {
        vector<Node *> in;
        inorder(root, in);
        int n = in.size();
        for (int i = 0; i < n - 1; i++)
        {
            in[i]->left = NULL; // Set left child to NULL
            in[i]->right = in[i + 1]; // Link to the next node in inorder traversal
        }
        in[n - 1]->right = NULL; // Last node's right should also be NULL
        in[n - 1]->left = NULL; // Last node's left should also be NULL
        return in[0];
    }
};
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(8);

    Solution sol;
    Node *flattenedRoot = sol.flattenBST(root);

    Node *current = flattenedRoot;
    while (current)
    {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;

    return 0;
}