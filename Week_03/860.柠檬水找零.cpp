/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    bool lemonadeChange(vector<int>& bills) {
        int n5 = 0, n10 = 0, n20 = 0;
        for(auto& n: bills) {
            if (n == 5) {
                n5 ++;
            }
            else if (n == 10) {
                n10 ++;
                n5 --;
            }
            else {
                n20 ++;

                if (n10 > 0) {
                    n10 --;
                    n5 --;
                }
                else {
                    n5 -= 3;
                }
            }

            if (n5 < 0 || n10 < 0 || n20 < 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

