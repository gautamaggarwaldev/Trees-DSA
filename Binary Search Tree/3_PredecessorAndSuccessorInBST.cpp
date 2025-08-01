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
    void preorder(Node *root, vector<int> &pre)
    {
        if (root == NULL)
            return;
        pre.push_back(root->data);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<int> pre;
        preorder(root, pre);
        int idx;
        for (int i = 0; i < pre.size(); i++)
        {
            if (pre[i] == key)
            {
                idx = i;
            }
        }
        Node *pree = new Node(pre[idx - 1]);
        Node *succ = new Node(pre[idx + 1]);
        return {pree, succ};
    }
};
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int key;
    cout << "Enter the key to find predecessor and successor: ";
    cin >> key;

    Solution sol;
    vector<Node *> result = sol.findPreSuc(root, key);
    cout << "Predecessor: " << result[0]->data << endl;

    cout << "Successor: " << result[1]->data << endl;
}