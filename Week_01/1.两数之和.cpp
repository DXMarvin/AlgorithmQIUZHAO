/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:

    // use map
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> memo_loc;
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (memo_loc.count(num)) {
                return {memo_loc[num], i};
            }
            memo_loc[target - num] = i;
        }
        
        return {-1, -1};
    }
};
// @lc code=end

