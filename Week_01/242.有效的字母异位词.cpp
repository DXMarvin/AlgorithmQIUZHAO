/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:

    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram_(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> char_num;

        for(char& c1: s) {
            char_num[c1] ++;
        }

        for(char& c2: t) {
            if (char_num[c2] == 0) {
                return false;
            }
            char_num[c2] --;
        }

        // auto sum =  [](int acc, const std::pair<char, int>& pair) {
        //    return acc+pair.second;
        // };

        // return std::accumulate(char_num.cbegin(), char_num.cend(), 0, sum) == 0;
        return true;
    }
};
// @lc code=end

