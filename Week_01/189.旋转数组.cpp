/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:


    // left shift
    // 1 2 | 3 4 5 6 7 8
    // 2 1 | 8 7 6 5 4 3
    // 3 4 5 6 7 8 | 1 2
    void rotate_(vector<int>& nums, int k) {
        if (k == 0) return;

        // k = (-k+nums.size())%nums.size();
        int len = nums.size();
        k = -(k%len)+len;
        // std::cout << "k:" << k << '\n';
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }


    // right shift
    // 1 2 | 3 4 5 6 7 8
    // 8 7 6 5 4 3 | 2 1
    // 7 8 | 1 2 3 4 5 6
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;

        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }
};
// @lc code=end

