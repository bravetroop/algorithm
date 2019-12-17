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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> vec1;
        vector<TreeNode*> vec2;
        bool init = false;
        int maxNum = 0;

        if (root == NULL) {
            return result;
        }

        vec1.push_back(root);

        while (!vec1.empty()) {
            TreeNode *pNode = vec1.back();
            if(init == false || pNode->val > maxNum) {
                maxNum = pNode->val;
                init = true;
            }

            if (pNode->left) {
                vec2.push_back(pNode->left);
            }

            if (pNode->right) {
                vec2.push_back(pNode->right);
            }

            vec1.pop_back();
            if (vec1.empty()) {
                result.push_back(maxNum);
                maxNum = 0;
                if (!vec2.empty()) {
                    vec1 = vec2;
                    vec2.clear();
                    init = false;
                }
            }
        }

        return result;
    }
};
