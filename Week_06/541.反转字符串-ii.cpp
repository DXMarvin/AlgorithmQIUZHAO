/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {

        int start = 0;
        while (start + 2*k < s.size())
        {
            std::reverse(s.begin()+start, s.begin()+start+k);
            start += 2*k;
        }

        std::reverse(s.begin()+start, min(s.end(), s.begin()+start+k));
        
        return s;
    }
};
// @lc code=end

