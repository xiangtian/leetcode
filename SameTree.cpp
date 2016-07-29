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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q==NULL)
        {
            return true;
        }

        if((p == NULL) || (q == NULL) || (p->val != q->val)) {
            return false;
        }

        bool isLeftEqual = isSameTree(p->left, q->left);
        bool isRightEqual = isSameTree(p->right, q->right);
        return isLeftEqual && isRightEqual;
    }
public:
    void testCase()
    {
        TreeNode* tree1 = new TreeNode(0);
        tree1->left = new TreeNode(1);
        tree1->right = new TreeNode(2);
        tree1->left->left = new TreeNode(3);
        tree1->left->right = new TreeNode(4);
        tree1->right->left = new TreeNode(5);
        TreeNode* tree2 = new TreeNode(0);
        tree2->left = new TreeNode(1);
        tree2->right = new TreeNode(2);
        tree2->left->left = new TreeNode(3);
        tree2->left->right = new TreeNode(4);
        tree2->right->left = new TreeNode(5);
        cout << isSameTree(tree1, tree2) << endl;
        tree2->right->left = NULL;
        cout << isSameTree(tree1, tree2) << endl;;
        tree2->right->left = new TreeNode(6);
        cout << isSameTree(tree1, tree2) << endl;;
        cout << isSameTree(NULL, NULL) << endl;;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
