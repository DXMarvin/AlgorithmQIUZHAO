/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    void dfs_fill(
        vector<vector<int>>& M,
        vector<bool>& visited,
        int cur_id
    ) {
        // recursion terminator
        if (visited[cur_id]) {
            return;
        }
        visited[cur_id] = true;

        // process
        for (int j = 0; j < M.size(); ++j) {

            if (visited[j]) {
                continue;
            }

            if (M[cur_id][j]) {

                // drill down
                dfs_fill(M, visited, j);

                // optional restore
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {

        auto visited = vector<bool> (M.size(), false);
        auto cnt = 0;
        for (int i = 0; i < M.size(); ++i) {
            if (!visited[i]) {
                ++ cnt;
                dfs_fill(M, visited, i);
            }
        }

 
        return cnt;
    }
};
// @lc code=end

