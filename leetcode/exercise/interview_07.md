输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

 

限制：

0 <= 节点个数 <= 5000

~~~cpp
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
    typedef vector<int>::iterator AUTO;

    TreeNode* rebuild(AUTO preorder_begin, AUTO inorder_begin, AUTO inorder_end) {
        if (inorder_begin == inorder_end) {
            return NULL;
        }

        int value = *preorder_begin;
        TreeNode* top = new TreeNode(value);
        
        //中序遍历，查找元素，元素左边的是左子树，元素右边的是右子树
        auto it_mid = find(inorder_begin, inorder_end, value);
        //左子树长度
        int leftLen = it_mid - inorder_begin;

        //下一次从下一个元素构建左子树
        top->left = rebuild(preorder_begin + 1, inorder_begin, it_mid);
        //右子树的起始元素
        top->right = rebuild(preorder_begin + (leftLen + 1), it_mid+1, inorder_end);

        return top;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //前序遍历第一个节点为根节点，然后看其在中序遍历中的偏移为K，
        //前序遍历K左面的为左子树，K右面的为右子树
        //依次递归
        TreeNode* top = NULL;
        top = rebuild(preorder.begin(), inorder.begin(), inorder.end());

        return top;
    }
};
~~~