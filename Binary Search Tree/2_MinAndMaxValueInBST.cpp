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
    int minValue(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    int maxValue(Node *root)
    {
        Node *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->data;
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

    Solution sol;
    cout << "Minimum value in BST: " << sol.minValue(root) << endl;
    cout << "Maximum value in BST: " << sol.maxValue(root) << endl;

    return 0;
}