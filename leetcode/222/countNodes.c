/*
 * countNodes.c
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
    void traverseTree(TreeNode* root, int* num) {
        if(root == 0) {
            return;
        }
        *num = *num + 1;
        traverseTree(root->left, num);
        traverseTree(root->right, num);
    }

    int countNodes(TreeNode* root) {
        int num = 0;
        traverseTree(root, &num);
        return num;
    }
};
