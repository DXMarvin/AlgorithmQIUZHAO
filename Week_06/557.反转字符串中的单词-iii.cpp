/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string res, cur;
        while (ss >> cur)
        {
            std::reverse(cur.begin(), cur.end());
            res = res + " " + cur;
        }
        
        return res.empty()? "": res.substr(1, res.size()-1);
    }
};
// @lc code=end

