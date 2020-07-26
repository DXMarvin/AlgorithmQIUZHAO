/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        // recursion terminator
        if (!root) {
            return {};
        }

        
        // process
        // drill down
        vector<int> res = inorderTraversal(root->left);
        res.push_back(root->val);
        auto r = inorderTraversal(root->right);

        std::copy(r.cbegin(), r.cend(), std::back_inserter(res));

        // optional back

        return res;
    }
};
// @lc code=end

