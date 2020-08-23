/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    int firstUniqChar(string s) {
        unordered_map<char, int> char2num;
        std::for_each(s.cbegin(), s.cend(), 
            [&char2num](const char& c){char2num[c]++;});

        for(int i = 0; i < s.size(); ++i) {
            if (char2num[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }


    int firstUniqChar_lengthy(string s) {

        vector<int> first_num_vec(s.size(), 0);
        map<char, int> char2first;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (char2first.count(c) == 0) {
                char2first[c] = i;
            }
            first_num_vec[char2first[c]] ++;
        }

        for (int i = 0; i < first_num_vec.size(); ++i) {
            if (first_num_vec[i] == 1) {
                return i;
            }
        }

        return -1;
    }

};
// @lc code=end

