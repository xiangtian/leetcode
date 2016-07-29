#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) {
            return false;
        }
        int tmpSum = 0;
        TreeNode* lastNode = NULL;
        TreeNode* p = root;
        stack<TreeNode*> nodes;
        while(p != NULL || !nodes.empty()) {
            if(p)
            {
                tmpSum += p->val; // add when add to stack
                if (isLeaf(p) && tmpSum == sum) {
                    return true;
                }

                nodes.push(p);
                p = p->left;
            }
            else
            {
                if(!nodes.empty())
                {
                    p = nodes.top();
                    if(p->right && p->right != lastNode)
                    {
                        p = p->right;
                    }
                    else
                    {
                        lastNode = p;
                        nodes.pop();
                        tmpSum -= p->val; // sub when pop from stack
                        p = NULL;
                    }
                }
            }
        }
        return false;
    }

private:
    bool isLeaf(TreeNode* node)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return true;
        }
        return false;
    }

public:
    void testCase()
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->left->left = new TreeNode(11);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        root->right->right->right = new TreeNode(1);
        cout << hasPathSum(root, 22) << endl;
        cout << hasPathSum(root, 26) << endl;
        cout << hasPathSum(root, 25) << endl;
        cout << hasPathSum(root, 18) << endl;
        cout << hasPathSum(root, 9) << endl;
    }
};

int main(void)
{
    Solution s;
    s.testCase();
}
