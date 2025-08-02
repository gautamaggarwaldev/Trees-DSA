#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void inorder1(Node *root1, vector<int> &in1)
    {
        if (root1 == NULL)
            return;
        inorder1(root1->left, in1);
        in1.push_back(root1->data);
        inorder1(root1->right, in1);
    }
    void inorder2(Node *root2, vector<int> &in2)
    {
        if (root2 == NULL)
            return;
        inorder2(root2->left, in2);
        in2.push_back(root2->data);
        inorder2(root2->right, in2);
    }
    vector<int> mergeArray(vector<int> &in1, vector<int> &in2)
    {
        int n = in1.size();
        int m = in2.size();

        vector<int> merged(n + m);

        for (int i = 0; i < n; ++i)
        {
            merged[i] = in1[i];
        }
        for (int j = 0; j < m; ++j)
        {
            merged[n + j] = in2[j]; 
        }

        sort(merged.begin(), merged.end());
        return merged;
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> in1;
        vector<int> in2;
        inorder1(root1, in1);
        inorder2(root2, in2);

        return mergeArray(in1, in2);
    }
};
int main()
{
    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->right = new Node(8);

    Node *root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(12);
    root2->left->left = new Node(5);
    root2->left->right = new Node(9);

    Solution sol;
    vector<int> mergedArray = sol.merge(root1, root2);

    cout << "Merged and sorted array: ";
    for (int val : mergedArray)
        cout << val << " ";
    cout << endl;

    return 0;
}