/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> memo;

        for (auto& s: strs) {
            string key = s;
            std::sort(key.begin(), key.end());
            memo[key].push_back(s);
        }

        // vector<vector<string>> res(memo.begin(), memo.end());

        vector<vector<string>> res;
        // std::transform(memo.begin(), memo.end(), std::back_insert_iterator(res), [](auto& vec) {return vec;});
        // for(string& k: memo) {
        // for(auto const& x: memo) {
        for(const auto& x: memo) {
            res.push_back(x.second);
        }
        return res;
        
    }
};
// @lc code=end

