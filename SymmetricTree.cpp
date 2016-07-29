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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL) {
            return true;
        }

        if(left == NULL || right == NULL || left->val != right->val)
        {
            return false;
        }

        bool isLeftEqual  = isSameTree(left->left, right->right);
        bool isRightEqual = isSameTree(left->right,right->left);
        return isLeftEqual && isRightEqual;
    }

 public:
    void testCase() 
    {
        TreeNode* root = new TreeNode(0);
        cout <<isSymmetric(root) << endl;
        root->left = new TreeNode(1);
        root->right = new TreeNode(1);
        cout <<isSymmetric(root) << endl;
        root->left->left = new TreeNode(2);
        root->right->right = new TreeNode(2);
        cout <<isSymmetric(root) << endl;
        root->right->right->right = new TreeNode(3);
        cout <<isSymmetric(root) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
