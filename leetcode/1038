#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode treeNode[9] = {0};

void constructBinSearchTree() {
    int index = 4;
    treeNode[index].val = index; treeNode[index].left = &treeNode[1]; treeNode[index].right = &treeNode[6];

    index = 1;
    treeNode[index].val = index; treeNode[index].left = &treeNode[0]; treeNode[index].right = &treeNode[2];

    index = 0;
    treeNode[index].val = index; treeNode[index].left = 0; treeNode[index].right = 0;

    index = 2;
    treeNode[index].val = index; treeNode[index].left = 0; treeNode[index].right = &treeNode[3];

    index = 3;
    treeNode[index].val = index; treeNode[index].left = 0; treeNode[index].right = 0;

    index = 6;
    treeNode[index].val = index; treeNode[index].left = &treeNode[5]; treeNode[index].right = &treeNode[7];

    index = 5;
    treeNode[index].val = index; treeNode[index].left = 0; treeNode[index].right = 0;

    index = 7;
    treeNode[index].val = index; treeNode[index].left = 0; treeNode[index].right = &treeNode[8];

    index = 8;
    treeNode[index].val = index; treeNode[index].left = 0; treeNode[index].right = 0;
}

void dfs(struct TreeNode* node) {
    if(0 == node) {
	return;
    }
    dfs(node->left);
    printf("%d,", node->val);
    dfs(node->right);
}

struct TreeNode* stStack[9] = {0};

void bfs(struct TreeNode* node) {
    int num = 0;
    int index = 0;

    stStack[num++] = node;

    while(index < 9) {
	node = stStack[index];
	printf("%d,", stStack[index]->val);

	if(node->left) {
	    stStack[num++] = node->left;
	}

	if(node->right) {
	    stStack[num++] = node->right;
	}

	++index;
    }
}

int total = 0;
void bstToGst(struct TreeNode* node) {
    if(0 == node) {
	return;
    }
    bstToGst(node->right);
    node->val += total;
    total = node->val;
    bstToGst(node->left);
}

int main()
{
    constructBinSearchTree();
    dfs(&treeNode[4]);
    printf("\n");

    bfs(&treeNode[4]);
    printf("\n");

    bstToGst(&treeNode[4]);

    bfs(&treeNode[4]);
    printf("\n");
    return 0;
}
