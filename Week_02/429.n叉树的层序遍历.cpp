/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

#include <vector>
#include <queue>
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

    void bfs(Node* root, vector<vector<int>>& res) {
        if (!root) {
            return;
        }

        queue<Node*> que;
        que.push(root);

        while (! que.empty())
        {
            vector<int> res_level;
            int q_size = que.size();
            // std::cout << "q size:" << q_size << '\n';
            while (q_size --)
            {
                Node* n = que.front();
                que.pop();

                if (!n) {
                    continue;
                }

                // std::cout << "n val:" << n->val << '\n';
                res_level.push_back(n->val);

                for(auto& child: n->children) {
                    que.push(child);
                }
            }

            res.push_back(res_level);
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        bfs(root, res);
        
        return res;
    }
};
// @lc code=end

