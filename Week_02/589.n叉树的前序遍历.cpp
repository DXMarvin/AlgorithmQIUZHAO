/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

#include <vector>
using namespace std;

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        // recursion terminator
        if (!root) {
            return {};
        }

        vector<int> res {root->val};

        for(auto& n: root->children) {
            auto r = preorder(n);
            std::copy(r.cbegin(), r.cend(), std::back_inserter(res));
        }

        return res;
    }
};
// @lc code=end

