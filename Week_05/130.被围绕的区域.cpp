/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<vector<int>> adj_steps {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = 0, n = 0;

    void dfs_border(
        vector<vector<char>>& board,
        int cur_i, int cur_j
    ) {
        // auto m = board.size(), n = board[0].size();

        // recursion terminator
        if (cur_i < 0 || cur_i >= m || cur_j < 0 || cur_j >= n) {
            return;
        }
        if (board[cur_i][cur_j] != 'O') {
            return;
        }

        // std::cout << "cur i j: " << cur_i << ", " << cur_j << ": " << '\n';

        board[cur_i][cur_j] = '1';

        for (auto& dij: adj_steps) {
            dfs_border(board, cur_i+dij[0], cur_j+dij[1]);
        }
    }

    void solve(vector<vector<char>>& board) {
        // auto m = board.size();
        m = board.size();
        if (m == 0) {
            return;
        }
        // auto n = board[0].size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O') {
                    dfs_border(board, i, j);
                }
            }
        }

        for(auto& vec: board) {
            for (auto& v: vec) {
                if (v == 'O') {
                    v = 'X';
                }
                else if (v == '1') {
                    v = 'O';
                }
            }
        }
    }
};
// @lc code=end

