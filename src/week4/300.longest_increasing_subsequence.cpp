#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> lookup;
        init_lookup(nums, lookup);


        return -1;
    }

    int lookup_idx(vector<int>* lookup, int target, int lo, int hi) {

        return -1;
    }

    void init_lookup(vector<int>& nums, vector<int>& lookup) {
        vector<int> sorted_nums = vector<int>(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        lookup[0] = sorted_nums[0];
        int i = 1;
        for (auto num : sorted_nums) {
            if (lookup[i - 1] != num) {
                lookup.push_back(num);
                i++;
            }
        }
    }

    //     vector<int> dp(nums.size(), -1);
    //     int global_max = 0;
    //     for (int i = nums.size() - 1; i >= 0; i++) {
    //         int next_increasing_idx = next_increasing(nums, i);
    //         if (next_increasing_idx == -1)
    //             dp[i] = 1;
    //         else
    //             dp[i] = dp[next_increasing_idx] + 1;
    //         global_max = max(dp[i], global_max);
    //     }
    //     return global_max;
    //
    // int next_increasing(vector<int>& nums, int i) {
    //     for (int k = i + 1; k < nums.size(); k++)
    //         if (nums[k] > nums[i])
    //             return k;
    //     return -1;
    // }

};

