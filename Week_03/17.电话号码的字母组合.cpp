/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:

    auto buildMap() {
        return unordered_map<char, string> {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
    }

    void dfs(
        vector<string>& res,
        string& cur,
        int cur_id,
        unordered_map<char, string>& phone_m,
        const string& digits
    ) {
        // recursion terminator
        if (cur_id == digits.size()) {
            res.push_back(cur);
            return;
        }

        // process
        for (char c: phone_m[digits[cur_id]]) {
            cur.push_back(c);
            dfs(res, cur, cur_id+1, phone_m, digits);
            cur.pop_back();
        }

        // drill down
        // optioanl restore
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }

        auto phone_m = buildMap();

        vector<string> res;
        string cur;
        dfs(res, cur, 0, phone_m, digits);

        return res;
    }
};
// @lc code=end

