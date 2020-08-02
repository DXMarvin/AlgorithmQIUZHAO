/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    double myPow_l(double x, long n) {

        if (x == 0.0 || x == 1.0) {
            return x;
        }
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        if (n < 0) {
            return myPow_l(1.0/x, -n);
        }

        auto p = myPow_l(x, n >> 1);

        return n&1? p*p*x: p*p;
    }


    double myPow(double x, int n) {
        return myPow_l(x, n);
    }

};
// @lc code=end

