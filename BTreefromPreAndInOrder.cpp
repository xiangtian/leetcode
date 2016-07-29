#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootVal = preorder[i];
        TreeNode* root = new TreeNode(preorder[i]);
        vector<int>::iterator begin = inorder.begin();
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), rootVal);
        vector<int>::iterator end = inorder.end();
        root->left = buildTreeInternal(begin, it);
        root->right = buildTreeInternal(it, end);
        return root;
    }
private:
    TreeNode* createNode()
    {
       i
    }

};




















