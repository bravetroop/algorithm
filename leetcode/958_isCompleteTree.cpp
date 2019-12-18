/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isCompleteTree(TreeNode *root)
    {
        bool hasNullChild = false;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();

            if (node) {
                if (hasNullChild) {
                    return false;
                }
                que.push(node->left);
                que.push(node->right);
            } else {
                hasNullChild = true;
            }
        }

        return true;
    }
};
