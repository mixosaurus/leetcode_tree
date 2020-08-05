#pragma once
#include <iostream>
//#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {};
};

class Solution {
public:
    int sumOfLeftLeavesRecursion(TreeNode* root, string a);
    int sumOfLeftLeaves(TreeNode* root);
};

