/*
 * kthSmallest.c
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
    void traverseTree(TreeNode* root, int k, int *num, bool *find, int * val) {
        if ( (0 == root) || (*find)) {
            return;
        }
        traverseTree(root->left, k, num, find, val);
        *num = *num + 1;
        if(*num == k) {
            *find = true;
            *val = root->val;
            return;
        }
        traverseTree(root->right, k, num, find, val);
    }

    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        int num = 0;
        bool find = false;

        traverseTree(root, k, &num, &find, &val);
        return val;
    }
};

