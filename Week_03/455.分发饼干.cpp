/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        // 1 2 3 
        // 1 1 2
        int i = 0, j = 0, ans = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j]) {
                ++i;
                ++j;
                ++ ans;
            }
            else {
                ++j;
            }
        }
        
        return ans;
    }
};
// @lc code=end

