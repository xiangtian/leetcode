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
    void flatten(TreeNode* root) {
        TreeNode* p = root; 
        if(p == NULL) {
            return;
        }
        stack<TreeNode*> nodes;
        TreeNode* lastNode = NULL;
        while(p != NULL || !nodes.empty())
        {
            if(p) {
                if(p->right)
                {
                    nodes.push(p->right);
                }

                TreeNode* left = p->left;
                p->left = NULL;
                // if not root
                if(lastNode) {
                    lastNode->right = p;
                }
                lastNode = p;
                p = left;
            }
            else
            {
                if(!nodes.empty()) {
                    p = nodes.top();
                    nodes.pop();
                }
            }
        }
    }
public:
    void testCase() 
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right->right = new TreeNode(6);
        flatten(root);
        TreeNode* p = root;
        while(p)
        {
            cout << p->val << " ";
            p = p->right;
        }
        cout << endl;
    }
    
};

int main(void)
{
    Solution s;
    s.testCase();
}
