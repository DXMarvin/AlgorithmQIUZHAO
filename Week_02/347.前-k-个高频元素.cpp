/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        using m_T = pair<int, int>;

        unordered_map<int, int> nums_map;

        for(auto& n: nums) {
            nums_map[n] ++;
        }

        // http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/
        auto cmp = [](m_T& p1, m_T& p2) {return p1.second < p2.second;} ;

        priority_queue<m_T, std::vector<m_T>, decltype(cmp)> que(cmp);; 
        
        for(auto& kv: nums_map) {
            que.push(kv);
        }

        vector<int> res;
        while (k--)
        {
            res.push_back(que.top().first);
            que.pop();
        }
        
        return res;
    }
};
// @lc code=end

