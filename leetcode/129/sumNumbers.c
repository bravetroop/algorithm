/*
 * sumNumbers.c
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
    void midOrder(TreeNode* root, int num) {
        if(root == 0) {
            return;
        }
        num = num * 10 + root->val;

        if ( (root->left == 0)
             && (root->right == 0) ) {
            total += num;
        } else {
            midOrder(root->left, num);
            midOrder(root->right, num);
        }
    }

    int sumNumbers(TreeNode* root) {
        midOrder(root, 0);
        return total;
    }
private:
    int total;
};


