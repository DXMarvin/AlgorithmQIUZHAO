/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        // 2 1 4 3, will give:
        // 4 3 2 1
        // if not inside, will get 0
        // thus, if inside, we can want map[i] > map[j], 
        // thus to make i to be front for cmp
        map<int, int> arr2_m;
        for(int i = 0; i < arr2.size(); ++i) {
            arr2_m[arr2[i]] = arr2.size()-i;
        }

        auto cmp = [&arr2_m](int a, int b) {
            if (arr2_m[a] == 0 && arr2_m[b] == 0) {
                return a < b;
            }
            return arr2_m[a] > arr2_m[b];
        };
        
        std::sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }


    vector<int> relativeSortArray_cmp(vector<int>& arr1, vector<int>& arr2) {

        map<int, int> arr2_m;
        for(int i = 0; i < arr2.size(); ++i) {
            arr2_m[arr2[i]] = i+1;
        }

        auto cmp = [&arr2_m](int a, int b) {
            auto a_in = arr2_m.count(a) > 0;
            auto b_in = arr2_m.count(b) > 0;

            if (a_in && b_in) {
                return arr2_m[a] < arr2_m[b];
            }
            
            if (a_in) {
                return true;
            }
            if (b_in) {
                return false;
            }

            return a < b;
        };
        
        std::sort(arr1.begin(), arr1.end(), cmp);
        return arr1;

    }
};
// @lc code=end

