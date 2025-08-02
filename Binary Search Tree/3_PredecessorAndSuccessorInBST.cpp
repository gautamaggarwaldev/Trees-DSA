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
    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *temp = root;
        Node *pre = NULL;
        Node *suc = NULL;
        // Search for key, remembering potential predecessors and successors
        while (temp)
        { // Add check for NULL
            if (temp->data == key)
                break; 
            else if (temp->data > key) // key is smaller move left
            {
                suc = temp;
                temp = temp->left;
            }
            else // key is larger move right
            {
                pre = temp;
                temp = temp->right;
            }
        }
        if (!temp)
        {
            // Key not found; return last valid pre, suc.
            return {pre, suc};
        }
        // Get max from left subtree
        Node *leftTree = temp->left; //
        while (leftTree)
        {
            pre = leftTree;
            leftTree = leftTree->right; // Traverse to the rightmost node in left subtree
        }
        // Get min from right subtree
        Node *rightTree = temp->right;
        while (rightTree)
        {
            suc = rightTree;
            rightTree = rightTree->left; // Traverse to the leftmost node in right subtree
        }
        return {pre, suc};
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