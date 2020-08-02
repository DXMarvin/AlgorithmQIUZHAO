/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include <vector>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:

    int majorityElement(vector<int>& nums) {
        int ans = INT_MAX, duplicate = 0;

        for(auto& n: nums) {

            if (ans == n) {
                duplicate ++;
                continue;
            }

            duplicate --;
            if (duplicate < 0) {
                ans = n;
                duplicate = 0;
            }

        }

        return ans;
    }

};
// @lc code=end

