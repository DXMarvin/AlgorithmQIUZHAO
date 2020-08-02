/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    // using SET = unordered_set<int>;
    using SET = set<int>;

    // set list
    // [[row], [col], [left-up -> right-down], [right-up -> left-down]]
    bool already_occupied(vector<SET>& used_sets, int i, int j) {
        return used_sets[0].count(i) || used_sets[1].count(j) || used_sets[2].count(i-j) || used_sets[3].count(i+j); 
    }

    void add_occupied(vector<SET>& used_sets, int i, int j) {
        used_sets[0].insert(i);
        used_sets[1].insert(j);
        used_sets[2].insert(i-j);
        used_sets[3].insert(i+j);
    }
    void del_occupied(vector<SET>& used_sets, int i, int j) {
        used_sets[0].erase(i);
        used_sets[1].erase(j);
        used_sets[2].erase(i-j);
        used_sets[3].erase(i+j);
    }

    void backtrack(
        vector<vector<int>>& res,
        vector<int>& cur,
        vector<SET>& used_sets,
        int cur_row,
        int n
    ) {
        // recursion terminator
        if (cur_row == n) {
            res.push_back(cur);
            return;
        }

        // process
        for(int col = 0; col < n; ++ col) {
            if (already_occupied(used_sets, cur_row, col)) {
                continue;
            }

            cur.push_back(col);
            add_occupied(used_sets, cur_row, col);

            backtrack(res, cur, used_sets, cur_row+1, n);

            del_occupied(used_sets, cur_row, col);
            cur.pop_back();
        }

        // drill down
        // optional restore
    }

    auto build_one(const vector<int>& cur, int num) {
        vector<string> res;
        // string seq (num, '.');
        std::transform(cur.cbegin(), cur.cend(), 
            std::back_inserter(res), 
            // [&](int n){seq[n] = 'Q'; return seq;}
            [&](int n){string seq (num, '.'); seq[n] = 'Q'; return seq;}
        );
        return res;
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<int>> res;
        vector<int> cur;
        vector<SET> used_sets(4);
 
        backtrack(res, cur, used_sets, 0, n);
        
        vector<vector<string>> res_str;
        std::transform(res.cbegin(), res.cend(), 
            std::back_inserter(res_str),
            [&](auto& r){return build_one(r, n);}
        );

        return res_str;
        
    }
};
// @lc code=end

