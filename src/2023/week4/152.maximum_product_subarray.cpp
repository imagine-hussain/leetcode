#include <vector>
#include <algorithm>

using std::vector;
using std::min;

using std::max;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int cum_max = nums[0];
        int cum_min = nums[0];
        int global_max = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int tmp_min = min(curr * cum_min, curr * cum_max);
            int tmp_max = max(curr * cum_min, curr * cum_max);
            cum_max = max(curr, tmp_max);
            cum_min = min(curr, tmp_min);
            global_max = max(cum_max, global_max);
        }

        return global_max;
    }
};
