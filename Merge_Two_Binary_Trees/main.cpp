#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//根据层次遍历序列和中序遍历序列生成二叉树
TreeNode* createBinaryTree(vector<int> level, vector<int> inorder) {
	if (level.size() == 0 || inorder.size() == 0) {
		return nullptr;
	}
	TreeNode* root = new TreeNode();
	vector<int> leftInorder;
	vector<int> rightInorder;
	vector<int> leftLevel;
	vector<int> rightLevel;
	//将中序遍历序列根据层次遍历序列首元素分割为两部分，即左右子树的中序遍历序列
	for (auto it = inorder.begin(); it != inorder.end(); it++) {
		if (*it == *level.begin()) {
			leftInorder=*(new vector<int>(inorder.begin(),it));
			rightInorder =*(new vector<int>(it+1,inorder.end()));
			break;
		}
	}
	//根据左右子树的中序遍历序列，找出相应的层次遍历序列
	for (auto it = level.begin()+1; it != level.end(); it++) {	
		vector<int>::iterator iLeftLevel = find(leftInorder.begin(), leftInorder.end(), *it);
		vector<int>::iterator iRightLevel = find(rightInorder.begin(), rightInorder.end(), *it);
		if(iLeftLevel!= leftInorder.end()){
			leftLevel.push_back(*iLeftLevel);
		}
		if (iRightLevel != rightInorder.end()) {
			rightLevel.push_back(*iRightLevel);
		} 
	}
	root->val = *level.begin();
	root->left = createBinaryTree(leftLevel,leftInorder);
	root->right = createBinaryTree(rightLevel,rightInorder);
	return root;
}

//中序遍历，非递归
void traverseInorderNonRecursion(TreeNode* root) {
	if (root == nullptr) {
		cout << "二叉树为空" << endl;
		return;
	}
	stack<TreeNode*> stack;
	TreeNode* p = root;
	while (!stack.empty() || p != nullptr) {
		while (p!=nullptr) {
			stack.push(p);
			p = p->left;
		}
		if (!stack.empty()) {
			p = stack.top();
			stack.pop();
			cout << p->val << " ";
			p = p->right;
		}
	}
	cout << endl;
}

//前序遍历，非递归
void traversePreorderNonRecursion(TreeNode* root) {
	if (root == nullptr) {
		cout << "二叉树为空" << endl;
		return;
	}
	stack<TreeNode*> stack;
	TreeNode* p = nullptr;
	stack.push(root);
	while (!stack.empty()) {
		p = stack.top();
		stack.pop();
		cout << p->val << " ";
		if (p->right != nullptr) {
			stack.push(p->right);
		}
		if (p->left != nullptr) {
			stack.push(p->left);
		}
	}
}

//617. 合并二叉树
int main(){
	TreeNode* t1 = createBinaryTree(
		*(new vector<int>({ 1,3,2,5 })), *(new vector<int>({ 5,3,1,2 }))
	);
	TreeNode* t2 = createBinaryTree(
		*(new vector<int>({ 2,1,3,4,7 })), *(new vector<int>({ 1,4,2,3,7 }))
	);
	traverseInorderNonRecursion((new Solution())->mergeTrees(t1,t2));
	system("pause");
	return 0;
}