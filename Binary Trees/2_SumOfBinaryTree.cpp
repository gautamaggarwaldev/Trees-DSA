#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution
{
public:
    int calculate(Node *root)
    {
        if (root == NULL)
            return 0;
        int ans =  root->data + calculate(root->left) + calculate(root->right);
        return ans;
    }
    int sumBT(Node *root)
    {
        int sum = calculate(root);
        return sum;
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
    cout << "Sum of Binary Tree: " << sol.sumBT(a) << endl;

    return 0;
}