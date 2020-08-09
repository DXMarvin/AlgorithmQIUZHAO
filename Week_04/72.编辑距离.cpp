/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

#include <string>
#include <map>
#include <tuple>
using namespace std;

// @lc code=start

class Solution {

private:
    map<pair<int, int>, int> memo;

public:

    int dfs(const string& w1, const string& w2, int id1, int id2) {
        // recursion terminator
        if (id1 == w1.size()) {
            return w2.size() - id2;
        } 
        else if (id2 == w2.size()) {
            return w1.size() - id1;
        }

        auto r = pair<int, int> {id1, id2};
        if (memo.count(r)) {
            return memo[r];
        }

        // process
        // drill down

        auto r11 = dfs(w1, w2, id1+1, id2+1); // delete s1 & s2

        if (w1[id1] == w2[id2]) {
            memo[r] = r11;
        }
        else {
            auto r10 = dfs(w1, w2, id1+1, id2); // delete s1
            auto r01 = dfs(w1, w2, id1, id2+1); // delete s2
            memo[r] = min(r01, min(r10, r11)) + 1;
        }

        return memo[r];
        // optional resotre
    }

    int minDistance(string word1, string word2) {
        return dfs(word1, word2, 0, 0);
    }
};
// @lc code=end

