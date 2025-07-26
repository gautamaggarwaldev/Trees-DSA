#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    Node *right;
    Node *left;
    int val;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    void preOrderTrav(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val); // Visit node
        preOrderTrav(root->left, ans); // Traverse left subtree
        preOrderTrav(root->right, ans); // Traverse right subtree
    }
    vector<int> preOrder(Node *root)
    {
        vector<int> ans;
        preOrderTrav(root, ans);
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
    vector<int> result = sol.preOrder(a);

    cout << "Preorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    
    return 0;
}