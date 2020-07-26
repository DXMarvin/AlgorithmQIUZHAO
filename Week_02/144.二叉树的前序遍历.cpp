/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> res {root->val};
        auto l = preorderTraversal(root->left);
        auto r = preorderTraversal(root->right);
        std::copy(l.cbegin(), l.cend(), std::back_inserter(res));
        std::copy(r.cbegin(), r.cend(), std::back_inserter(res));

        return res;
    }
};
// @lc code=end

