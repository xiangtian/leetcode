#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> nodes;
        if(root == NULL) {
            return nodes;
        }

        std::stack<TreeNode*> rightChildren;
        TreeNode* p = root;
        while(p != NULL || !rightChildren.empty()) {
            if(p)
            {
                nodes.push_back(p->val);
                if(p->right) {
                    rightChildren.push(p->right);
                }
                p = p->left;
            }
            else
            { 
                if(!rightChildren.empty()) {
                    p = rightChildren.top();
                    rightChildren.pop();
                }
            }
        }

        return nodes;
    }

public:
    void testCase() 
    {
        
        TreeNode* root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->right = new TreeNode(2);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(5);
        root->left->left = new TreeNode(4);
        root->left->left->left = new TreeNode(6);
        vector<int> v = preorderTraversal(root);
        printVector(v);
    }
private:
    void printVector(const vector<int>& v)
    {
        for(int i = 0; i < v.size(); i++) 
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    s.testCase();
}
