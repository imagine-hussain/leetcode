#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_max = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            global_max = max(nums[i], global_max);
        }

        return global_max;
    }
};
