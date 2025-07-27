#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void printPostorder(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->val << " ";
        s2.pop();
    }
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

    cout << "Postorder Traversal: ";
    printPostorder(a);
}