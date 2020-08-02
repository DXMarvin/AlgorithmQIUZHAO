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

    bool is_index_valid(int i, int j, const vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs_fill(
        int i, int j,
        vector<vector<bool>>& visited,
        const vector<vector<char>>& grid
    ) {

        // std::cout << "i: " << i << ", j: " << j << '\n'; 

        // recursion terminator
        if (!is_index_valid(i, j, grid) || visited[i][j] || grid[i][j] == '0'){
            return;
        }

        // process
        visited[i][j] = true;

        // drill down
        dfs_fill(i-1, j, visited, grid);
        dfs_fill(i, j-1, visited, grid);
        dfs_fill(i, j+1, visited, grid);
        dfs_fill(i+1, j, visited, grid);

        // optioanl resotre
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) {
                    continue;
                }
                count ++;
                dfs_fill(i, j, visited, grid);
            }
        }

        return count;
    }
};
// @lc code=end

