#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false; // odd => impossible

        int goal = sum / 2;
        // Do a knapsack of capacity `goal`

        int i_max = nums.size() + 1;
        int j_max = goal + 1;
        // dp[i][j] := if sum of `j` possible with first `i` elements
        vector<vector<bool>> dp(i_max, vector<bool>(j_max, false));

        dp_fill(dp, nums);
        // print_dp(dp);

        cout << "done" << endl;
        return dp[nums.size()][goal];
    }

    void dp_fill(vector<vector<bool>>& dp, vector<int>& nums) {
        for (int i = 0; i <= dp.size(); i++) {
            for (int j = 0; j <= dp[i].size(); j++) {
                dp[i][j] = eval_dp(dp, nums, i, j);
            }
        }
    }

    inline bool eval_dp(vector<vector<bool>>& dp, vector<int>& nums, int i, int j) {
        cout << "(" << i << ", " << j << ");" << endl;
        if (i == 0) // only 0 costpossible with 0 elems
            return j == 0;
        if (j == 0) // 0 cost always possible
            return true;

        // Cases:
        //  - don't use nums[i] => first `i - 1` elems with `j` goal
        if (dp[i - 1][j])
            return true;
        //  - use nums[i] => first `i - 1` elems with `j` goals
        // No negative wegith allowed
        int val = nums[i - 1];
        cout << "val: " << val << endl;
        if ((j - nums[i - 1]) < 0) {
            cout << "f " << endl;
        } else {
            return dp[i - 1][j - val];
        }
        // return ((j - nums[i - 1]) < 0) ? false : dp[i - 1][j - nums[i - 1]];
        //
        return false;
    }


};
