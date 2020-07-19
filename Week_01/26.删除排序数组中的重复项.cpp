/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:


    // 0 1 2 3 4 5 6
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int slow = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[slow] != nums[i]) {
                nums[++slow] = nums[i];
            }
        }
        return slow+1;
    }
};
// @lc code=end
