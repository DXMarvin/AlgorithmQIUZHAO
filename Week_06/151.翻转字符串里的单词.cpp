/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
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
            res = " " + cur + res;
        }
        return res.empty()? "": res.substr(1, res.size()-1);
    }

    string reverseWords_vec(string s) {
        vector<string> vec;
        string cur;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                cur.push_back(s[i]);
                continue;
            }
            
            if (cur.size() > 0) {
                vec.push_back(cur);
                cur = "";
            }
        }
        if (cur.size() > 0) {
            vec.push_back(cur);
            cur = "";
        }


        auto len = vec.size();
        if (len == 0) {
            return "";
        }

        string res = vec[len-1];
        for (int i = len-2; i >= 0; --i) {
            res += " ";
            res += vec[i];
        }
        
        return res;
    }
};
// @lc code=end

