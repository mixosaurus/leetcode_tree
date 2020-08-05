#include "solution.h"
#include <stack>
#include <utility>

//flagָʾ��ǰ�ڵ�Ϊ�丸�ڵ�����ӻ����Һ���
int Solution::sumOfLeftLeavesRecursion(TreeNode* root,string flag) {
    if (root == nullptr) {
        return 0;
    } else if (root->left == nullptr && root->right == nullptr&&flag=="left") {
        return root->val;
    }
    return sumOfLeftLeavesRecursion(root->left,"left")+sumOfLeftLeavesRecursion(root->right,"right");
}

int sumOfLeftLeavesNonRecursion(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } 
    int sum = 0;
    stack<pair<TreeNode*,string>*> stack;
    pair<TreeNode*, string>* p = nullptr;
    stack.push(new pair<TreeNode*,string>(root,""));

	while (!stack.empty()) {
		p = stack.top();
		stack.pop();
        if (p->second == "left"&&p->first->left==nullptr&&p->first->right==nullptr) {
            sum = sum + p->first->val;
        }
		if (p->first->right != nullptr) {
			stack.push(new pair<TreeNode*,string>(p->first->right,"right"));
		}
		if (p->first->left != nullptr) {
			stack.push(new pair<TreeNode*,string>(p->first->left,"left"));
		}
	}
    return sum;;
}

int Solution::sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeavesNonRecursion(root);
}