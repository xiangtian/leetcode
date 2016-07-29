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
    bool isValidBST(TreeNode *root) {
        // null tree is BST
        if(root == NULL) {
            return true;
        }

        bool isLeftValidBST = true;
        if(root->left)
        {
            // leftChild->right
            TreeNode* rightestChild = root->left->right;
            // find rightest chidl
            while(rightestChild) {
                if (rightestChild->val >= root->val) {
                    isLeftValidBST = false;
                    break;
                }
                rightestChild = rightestChild->right;
            }
            
            // leftChild
            if (isLeftValidBST && root->left->val < root->val) {
                isLeftValidBST = isValidBST(root->left);
            }
            else
            {
                isLeftValidBST = false;
            }
        }

        bool isRightValidBST = true;
        if (root->right) {
            // rightChild->leftChild
            TreeNode* leftestChild = root->right->left;
            // find leftest child
            while(leftestChild) {
                if (leftestChild->val <= root->val) {
                    isRightValidBST = false;
                    break;
                }
                leftestChild = leftestChild->left;
            }

            if (isRightValidBST && root->right->val > root->val) {
                isRightValidBST = isValidBST(root->right);
            }
            else
            {
                isRightValidBST = false;
            }
            
        }
        return isLeftValidBST && isRightValidBST;
    }
public:
    void testCase()
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(12);
        cout << isValidBST(root) << endl; // 1
        root->right->right->left = new TreeNode(1);
        cout << isValidBST(root) << endl; // 0
        root->right->right->left = new TreeNode(8);
        cout << isValidBST(root) << endl; // 0
        root->right->right->left = new TreeNode(9);
        cout << isValidBST(root) << endl; // 1
        // root->left->right = new TreeNode(7);
        // cout << isValidBST(root) << endl; // 0
        root->right->left->left = new TreeNode(5);
        cout << isValidBST(root) << endl; // 1

        TreeNode* singleNode = new TreeNode(7);
        cout << isValidBST(singleNode) << endl; // 1
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
