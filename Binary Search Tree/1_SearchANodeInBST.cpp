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
bool search(Node *root, int x)
{
    if (root == NULL || root->data == x)
        return root;
    if (x < root->data)
    {
        return search(root->left, x);
    }
    if (x > root->data)
        return search(root->right, x);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int x;
    cout << "Enter the value to search: ";
    cin >> x;

    if (search(root, x))
        cout << "Node found with value: " << x << endl;
    else
        cout << "Node not found with value: " << x << endl;

    return 0;
}