#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    void inorder(Node *root, vector<int> &in)
    {
        if (root == NULL)
            return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    int kthSmallest(Node *root, int k)
    {
        vector<int> in;
        inorder(root, in);

        if (k > in.size())
            return -1;
        else
            return in[k - 1]; // k is 1-based index, so we return in[k-1]
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

    int k;
    cout << "Enter the value of k to find the kth smallest element: ";
    cin >> k;

    Solution sol;
    int result = sol.kthSmallest(root, k);
    
    if (result != -1)
        cout << "The " << k << "th smallest element in the BST is: " << result << endl;
    else
        cout << "k is larger than the number of elements in the BST." << endl;

    return 0;
}