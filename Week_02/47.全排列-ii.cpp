/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <vector>
#include <algorithm>
#include <set>
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

            // if last same value is not used, we have no need to use this one also
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) {
                continue;
            }

            cur.push_back(nums[i]);
            visited[i] = true;

            backtrack(res, cur, visited, nums);

            cur.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> visited(nums.size(), false);

        backtrack(res, cur, visited, nums);
 
        return res;
    }


    vector<vector<int>> permuteUnique_stl(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        set<vector<int>> res_set{};
        do {
            res_set.insert(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return vector<vector<int>> {res_set.begin(), res_set.end()};
        // return vector<vector<int>>(res_set.begin(), res_set.end());
    }
};
// @lc code=end

