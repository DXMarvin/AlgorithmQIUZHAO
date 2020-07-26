/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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
    vector<int> postorder(Node* root) {
        // recursion terminator
        vector<int> res;
        if (!root) {
            return res;
        }

        // drill down
        for(auto& n: root->children) {
            auto r = postorder(n);
            std::copy(r.cbegin(), r.cend(), std::back_inserter(res));
        }

        // process
        res.push_back(root->val);
        return res;
        // reset status if necessary
    }
};
// @lc code=end

