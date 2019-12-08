/*
 * inorderTraversal.c
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
    void midOrder(TreeNode* root) {
        if(root->left) {
            midOrder(root->left);
        }
        arr.push_back(root->val);
        if(root->right) {
            midOrder(root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(root) {
            midOrder(root);
        }

        return arr;
    }

private:
    vector<int> arr;
};
