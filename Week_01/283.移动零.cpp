/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:

    void moveZeroes_(vector<int>& nums) {
       auto itr = std::remove_if(nums.begin(), nums.end(), [](int& i){return i == 0;});
       std::fill(itr, nums.end(), 0);
    }

    void moveZeroes__(vector<int>& nums) {
        int i = 0;
        for(auto& v: nums) {
            if (v != 0) {
                nums[i] = v;
                ++ i;
            }
        }

        std::fill(nums.begin()+i, nums.end(), 0);
    }

    void moveZeroes___(vector<int>& nums) {
        int cur = 0;
        for (auto& n: nums) {
            if (n!=0) {
                nums[cur++] = n;
            }
        }
        std::fill(nums.begin()+cur, nums.end(), 0);
    }


    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            std::swap(nums[cur++], nums[i]);
        }

        std::fill(nums.begin()+cur, nums.end(), 0);
    }

};
// @lc code=end

