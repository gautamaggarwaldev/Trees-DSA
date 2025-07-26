#include <iostream>
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
        this->right = NULL;
        this->left = NULL;
    }
};
void printBST(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    printBST(root->left);
    printBST(root->right);
}
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

    cout << "Binary Tree Created Successfully!" << endl;

    printBST(a);
}