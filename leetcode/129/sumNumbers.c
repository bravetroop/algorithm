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
    void preOrder(TreeNode* root, int num) {
        num = num * 10 + root->val;

        if ( (root->left == 0)
             && (root->right == 0) ) {
            total += num;
        } else {
        	if(root->left) {
        		preOrder(root->left, num);
        	}

        	if(root->right) {
        		preOrder(root->right, num);
        	}
        }
    }

    int sumNumbers(TreeNode* root) {
        if(root) {
        	preOrder(root, 0);
        }
        return total;
    }
private:
    int total;
};
