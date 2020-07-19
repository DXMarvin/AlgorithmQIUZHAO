/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.rbegin(), digits.rend());
        int len = digits.size();
        int up_num = 0;
        for(int i = 0; i < len; ++i) {
            if (res[i] != 9) {
                break;
            }
            ++ up_num;
        }

        // std::cout << "un:" << up_num << '\n';

        std::fill_n(res.begin(), up_num, 0);

        if (up_num == len) {
            res.push_back(1);
        }
        else {
            res[up_num] += 1;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

    vector<int> plusOne_(vector<int>& digits) {
        int up = 0;
        for(int i = digits.size()-1; i >=0; --i) {
            int add_v = i == digits.size()-1? 1: up;
            int num = digits[i] + add_v;

            digits[i] = num%10;
            if (num < 10) {
                up = 0;
                break;
            }

            up = 1;
        }

        if (up) {
            digits.insert(digits.begin(), {1});
        }
        return digits;
    }
};
// @lc code=end

