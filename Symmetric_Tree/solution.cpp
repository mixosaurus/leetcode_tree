#include "solution.h"
#include <iostream>
#include <cmath>

bool Solution::isSymmetric(TreeNode* child1,TreeNode* child2) {
    if (child1 == nullptr && child2 == nullptr) {
        return true;
    } else if (child1 == nullptr || child2 == nullptr) {
        return false;
    } else {
        if (child1->val == child2->val && isSymmetric(child1->left,child2->right) && isSymmetric(child1->right,child2->left)) {
            return true;
        } else {
            return false;
        }
    }
}

bool Solution::isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }
    return isSymmetric(root->left,root->right);
}
