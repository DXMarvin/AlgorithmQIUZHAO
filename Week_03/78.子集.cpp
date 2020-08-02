/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    void backtrack(
        vector<vector<int>>& res,
        vector<int>& cur,
        int cur_id,
        const vector<int>& nums
    ) {
        // recursion terminator
        res.push_back(cur);
        if (cur_id == nums.size()) {
            return;
        }

        // process

        // drill down
        for(int i = cur_id; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(res, cur, i+1, nums);
            cur.pop_back();
        }

        // optional restore
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;

        backtrack(res, cur, 0, nums);
       
       return res;
    }
};
// @lc code=end
