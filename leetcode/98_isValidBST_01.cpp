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
    void traverseTree(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        traverseTree(root->left);
        vec.push_back(root->val);
        traverseTree(root->right);
        return;
    }

    bool isValidBST(TreeNode* root) {
        if (NULL == root) {
            return true;
        }
        
        traverseTree(root);

        for (auto it = vec.begin(); it != vec.end()-1; ++it) {
            if (*it >= *(it+1)) {
                return false;
            }
        }

        return true;
    }
private:
    vector<int> vec;
};
