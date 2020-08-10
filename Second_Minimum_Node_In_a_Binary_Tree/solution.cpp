#include "solution.h"
#include <iostream>

//将当前节点和其孩子节点,共三个节点作为研究主体
//在这三个节点中找出第二小节点即可解决问题
//若当前节点值与其左孩子相等且与右孩子不相等，则当前节点的右孩子为第二小节点，另一种情况同理
int Solution::findSecondMinimumValue(TreeNode* root) {
    //null和叶子节点结束本次执行
    //每个节点的孩子节点数只能为0或2
    //因此只判断左右孩子之一是否存在即可确定是否为叶子节点
    if (root == nullptr || root->left == nullptr) {
        return -1;
    }
    int leftMin = findSecondMinimumValue(root->left);
    int rightMin = findSecondMinimumValue(root->right);
    //三节点相等
    if (root->left->val == root->val && root->right->val == root->val) {
        if (leftMin == -1) {
            return rightMin;
        } else if (rightMin == -1) {
            return leftMin;
        } else {
            return min(leftMin, rightMin);
        }
    } else if (root->val==root->left->val) {
        //当前节点的值与其左孩子相等
        if (leftMin == -1) {
            //右孩子较大，因此为第二小
            return root->right->val;
        } else {
            return min(leftMin, root->right->val);
        }
    } else {
        //当前节点值与其右孩子的值相等
        if (rightMin == -1) {
            //左孩子较大，因此为第二小
            return root->left->val;
        } else {
            return min(rightMin, root->left->val);
        }
    }
}
