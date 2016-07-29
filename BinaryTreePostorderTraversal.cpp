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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> nodes;
        if(root == NULL) {
            return nodes;
        }

        std::stack<TreeNode*> roots;
        TreeNode* p = root;
        TreeNode* lastNode = NULL;
        while(p != NULL|| !roots.empty()) {
            if(p)
            {
                roots.push(p);
                p = p->left;
            }
            else
            {
                if(!roots.empty()) {
                    p = roots.top();
                    // caution if p->right == lastNode stack.pop()
                    if(p->right && p->right != lastNode)
                    {
                        p = p->right;
                    }
                    else
                    {
                        lastNode = p;
                        nodes.push_back(p->val);
                        roots.pop();
                        p = NULL;
                    }
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
        vector<int> v = postorderTraversal(root);
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
