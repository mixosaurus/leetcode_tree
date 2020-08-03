#include "solution.h"

//将t2合并至t1，返回t1
TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1==nullptr&&t2==nullptr) {
        return nullptr;
    } else if(t1==nullptr){
        return t2;
    } else if (t2 == nullptr) {
        return t1;
    }
    t1->val= t1->val + t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
