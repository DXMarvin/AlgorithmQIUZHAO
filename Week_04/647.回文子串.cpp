/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:


    /*
        a b c b c b d
    */
    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); ++i) {

            for (int j = 0; i-j >= 0 && i+j+1 < s.size(); ++j)
            {
                if (s[i-j] != s[i+j+1]) {
                    break;
                }
                ++ ans;
            }

            for (int j = 0; i-j >= 0 && i+j < s.size(); ++j)
            {
                if (s[i-j] != s[i+j]) {
                    break;
                }
                ++ ans;
            }
        }

        return ans;
    }
};
// @lc code=end

