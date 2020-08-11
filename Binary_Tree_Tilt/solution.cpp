#include "solution.h"
#include <iostream>
#include <cmath>


int Solution::findTilt(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int currentTilt = abs(sumOfNodes(root->left) - sumOfNodes(root->right));
    return currentTilt + findTilt(root->left) + findTilt(root->right);
}

//当前子树所有节点之和
int Solution::sumOfNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->val+sumOfNodes(root->left)+sumOfNodes(root->right);
}
