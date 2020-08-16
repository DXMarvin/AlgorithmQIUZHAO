/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:

    // bool isPowerOfTwo(int n) {
    //     // long n = n_;

    //     return n & (-n) == n;
    // }

    bool isPowerOfTwo(int n_) {
        long n = n_;

        if (!n) {
            return false;
        }

        return !(n&(n-1));
    }
};
// @lc code=end

