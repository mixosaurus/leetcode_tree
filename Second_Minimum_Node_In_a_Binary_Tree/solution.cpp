#include "solution.h"
#include <iostream>

//����ǰ�ڵ���亢�ӽڵ�,�������ڵ���Ϊ�о�����
//���������ڵ����ҳ��ڶ�С�ڵ㼴�ɽ������
//����ǰ�ڵ�ֵ����������������Һ��Ӳ���ȣ���ǰ�ڵ���Һ���Ϊ�ڶ�С�ڵ㣬��һ�����ͬ��
int Solution::findSecondMinimumValue(TreeNode* root) {
    //null��Ҷ�ӽڵ��������ִ��
    //ÿ���ڵ�ĺ��ӽڵ���ֻ��Ϊ0��2
    //���ֻ�ж����Һ���֮һ�Ƿ���ڼ���ȷ���Ƿ�ΪҶ�ӽڵ�
    if (root == nullptr || root->left == nullptr) {
        return -1;
    }
    int leftMin = findSecondMinimumValue(root->left);
    int rightMin = findSecondMinimumValue(root->right);
    //���ڵ����
    if (root->left->val == root->val && root->right->val == root->val) {
        if (leftMin == -1) {
            return rightMin;
        } else if (rightMin == -1) {
            return leftMin;
        } else {
            return min(leftMin, rightMin);
        }
    } else if (root->val==root->left->val) {
        //��ǰ�ڵ��ֵ�����������
        if (leftMin == -1) {
            //�Һ��ӽϴ����Ϊ�ڶ�С
            return root->right->val;
        } else {
            return min(leftMin, root->right->val);
        }
    } else {
        //��ǰ�ڵ�ֵ�����Һ��ӵ�ֵ���
        if (rightMin == -1) {
            //���ӽϴ����Ϊ�ڶ�С
            return root->left->val;
        } else {
            return min(rightMin, root->left->val);
        }
    }
}
