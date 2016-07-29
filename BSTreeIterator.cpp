#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root)
        {
            mNodes.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mNodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = mNodes.top();
        mNodes.pop();
        TreeNode* node = top->right;
        while(node)
        {
            mNodes.push(node);
            node = node->left;
        }
        return top->val;
    }

private:
    stack<TreeNode*> mNodes;
};

int main(void)
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(4);
    root->left->left->left->right = new TreeNode(2);

    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) {
        cout << i.next()<< " ";
    }
}
 /*
  **
  Yes. Your next() runs in average O(1) time. The next()it is called n times, while in all the runtime of next(), each of the n nodes enters the stack at most 1 time (some nodes enter during construction) and leaves the stack exactly 1 time.
   And the space cost is O(h) time. The stack size grows only in addLeftNodes(). Each time addLeftNodes() finishes, the node at top of the stack is a leaf. At the same time, right below each node is its parent or the parent of its parent. Thus, after addLeftNodes(), the node sequence in stack forms a (sometimes incompleted) path from root to a leaf. Such a path always has a length less than the height of the tree
 */
