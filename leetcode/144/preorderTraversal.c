/*
 * preorderTraversal.c
 *
 *  Created on: Dec 8, 2019
 *      Author: shijie
 */

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
    void preorder(TreeNode* root) {
        if(0 == root) {
            return;
        }
        arr.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return arr;
    }
private:
    vector<int> arr;
};
