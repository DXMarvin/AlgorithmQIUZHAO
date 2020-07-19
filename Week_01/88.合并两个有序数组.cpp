/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    // num1: m, num2: n
    // back-put, from [m+n-1] -> 0
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if (m == 0) {
        //     nums1[0] = nums2[0];
        //     return;
        // }

        int slot = m+n-1;
        m -= 1;
        n -= 1;
        while (n>=0 && m>=0)
        {
            // std::cout << "m:" << m << ", n:" << n << '\n';
            int a = nums1[m], b = nums2[n];
            if (a >= b) {
                nums1[slot] = a;
                --m;
            }
            else {
                nums1[slot] = b;
                --n;
            }
            -- slot;
        }

        if (n >= 0) {
            std::copy(nums2.begin(), nums2.begin()+n+1, nums1.begin());
        }
    }
};
// @lc code=end

