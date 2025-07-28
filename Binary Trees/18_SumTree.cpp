#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    pair<bool, int> check(Node *root)
    {
        if (root == NULL)
            return {true, 0};
        if (root->left == NULL && root->right == NULL)
        {
            return {true, root->data};
        }
        pair<bool, int> Left = check(root->left);
        pair<bool, int> Right = check(root->right);

        bool left = Left.first;
        bool right = Right.first;
        bool condn = root->data == Left.second + Right.second;

        pair<bool, int> ans;
        if (left && right && condn) {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else {
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node *root) {

        return check(root).first;
    }
};
int main()
{
    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();
    Node *d = new Node();
    Node *e = new Node();

    a->data = 26;
    b->data = 10;
    c->data = 3;
    d->data = 4;
    e->data = 6;

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    Solution sol;
    cout << "Is the Binary Tree a Sum Tree? " << (sol.isSumTree(a) ? "Yes" : "No") << endl;

    return 0;
}