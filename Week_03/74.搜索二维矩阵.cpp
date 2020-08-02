/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool searchMatrix(
        vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        if (matrix[0][0] > target || matrix[m-1][n-1] < target)
        {
            return false;
        }
        
        vector<int> first_col;
        for(int i = 0; i < m; ++i) {
            first_col.push_back(matrix[i][0]);
        }
        first_col.push_back(INT_MAX);
        
        int idx = std::lower_bound(first_col.cbegin(), first_col.cend(), target) - first_col.cbegin();

        if (first_col[idx] == target) {
            return true;
        }
        idx --;

        // [[1,3],[5,7],[9,11]]\n1
        auto vec = matrix[idx];
        for(auto&c : vec) {
            std::cout << c << " ";
        }

        auto itr = std::lower_bound(vec.begin(), vec.end(), target);
        if (itr == vec.end()) {
            return false;
        }
        return *itr == target;
    }
};
// @lc code=end

