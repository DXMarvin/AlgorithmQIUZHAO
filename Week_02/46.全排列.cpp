/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:


    void backtrack(
        vector<vector<int>>& res,
        vector<int>& cur,
        vector<bool>& visited,
        vector<int>& nums
    ) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            cur.push_back(nums[i]);
            visited[i] = true;

            // drill down
            backtrack(res, cur, visited, nums);

            // optional back
            cur.pop_back();
            visited[i] = false;
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);

        backtrack(res, cur, visited, nums);
 
        return res;
    }


    vector<vector<int>> permute_(vector<int>& nums) {

        vector<vector<int>> res;

        // NOTE, next_permutation means we should permutate next seq, 
        // thus, we need to sort the seq first
        std::sort(nums.begin(), nums.end());

        do {
            res.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));


        return res;
    }
};
// @lc code=end

