/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

#include <iostream>

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto cnt = 0;

        while (n)
        {
            ++ cnt;
            n &= n-1;
        }
        
        return cnt;
    }
};
// @lc code=end

