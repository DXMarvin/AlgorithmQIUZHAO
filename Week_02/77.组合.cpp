/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:


    void backtrack(
        vector<vector<int>>& res,
        vector<int>& cur,
        int start,
        int n,
        int k
    ) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        if (start > n) {
            return;
        }


        for(int v = start; v <=n; ++v) {
            cur.push_back(v);
            backtrack(res, cur, v+1, n, k);
            cur.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
 
        backtrack(res, cur, 1, n, k);

        return res;
    }
};
// @lc code=end

