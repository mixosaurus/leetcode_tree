#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
	cout << endl;
}

//层次遍历
void traverseLevel(TreeNode* root) {
	if (root == nullptr) {
		cout << "二叉树为空" << endl;
		return;
	}
	queue<TreeNode*> queue;
	TreeNode* p = nullptr;
	queue.push(root);
	while (!queue.empty()) {
		p = queue.front();
		queue.pop();
		cout << p->val << " ";
		if (p->left != nullptr) {
			queue.push(p->left);
		}
		if (p->right != nullptr) {
			queue.push(p->right);
		}
	}
	cout << endl;
}

//手动建立二叉树，用于节点值允许重复的情况
TreeNode* createBinaryTreeManually() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	return root;
}

//101. 对称二叉树
int main(){
	TreeNode* tree=nullptr;
	//tree= createBinaryTree(
	//	*(new vector<int>({ 1,2,3 })), *(new vector<int>({ 2,1,3}))
	//);
	tree = createBinaryTreeManually();
	cout << boolalpha << (new Solution())->isSymmetric(tree) << endl;
	system("pause");
	return 0;
}