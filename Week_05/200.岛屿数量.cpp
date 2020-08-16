/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<vector<int>> adj_steps {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    auto get_adj(
        vector<vector<char>>& grid,
        int cur_i, int cur_j
    ) {
        // vector<pair<int, int>> res;
        vector<vector<int>> res;
        auto m = grid.size(), n = grid[0].size();

        for (auto& dij: adj_steps){
            auto i = cur_i+dij[0], j = cur_j+dij[1];
            if (i >= 0 && i < m && j >= 0 && j < n) {
                res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs_fill(
        vector<vector<char>>& grid,
        vector<vector<bool>>& visited,
        int cur_i, int cur_j
    ) {
        auto m = grid.size(), n = grid[0].size();
        // recursion terminator
        if (cur_i < 0 || cur_i >= m || cur_j < 0 || cur_j >= n || grid[cur_i][cur_j] == '0' || visited[cur_i][cur_j]) {
            return;
        }
        visited[cur_i][cur_j] = true;

        // process
        for (auto& dij: adj_steps) {
            dfs_fill(grid, visited, cur_i+dij[0], cur_j+dij[1]);
        }
    }


    void dfs_fill_1(
        vector<vector<char>>& grid,
        vector<vector<bool>>& visited,
        int cur_i, int cur_j
    ) {
        // recursion terminator
        if (grid[cur_i][cur_j] == '0' || visited[cur_i][cur_j]) {
            return;
        }
        visited[cur_i][cur_j] = true;

        // process
        for (auto& ij : get_adj(grid, cur_i, cur_j)) {
            // auto& i = ij.first, j = ij.second;
            auto& i = ij[0], j = ij[1];
            if (!grid[i][j] || visited[i][j]) {
                continue;
            }

            // drill down
            dfs_fill_1(grid, visited, i, j);
            // optional restore
        }

    }

    int numIslands(vector<vector<char>>& grid) {

        auto m = grid.size();
        if (m == 0) {
            return 0;
        }

        auto n = grid[0].size();

        auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
        auto ans = 0;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++ ans;
                    dfs_fill(grid, visited, i, j);
                }
            }
        }
 
        return ans;
    }
};
// @lc code=end

