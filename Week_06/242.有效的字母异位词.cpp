/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:

    bool isAnagram_sort(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram(string s, string t) {
        unordered_map<char, int> cm;
        std::for_each(s.cbegin(), s.cend(),
            [&cm](const char& c) {cm[c]++;});
        std::for_each(t.cbegin(), t.cend(),
            [&cm](const char& c) {cm[c]--;});

        return std::all_of(cm.cbegin(), cm.cend(), 
            [](const auto& ii) {return ii.second == 0;});
    }



};
// @lc code=end

