#include <vector>

using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int lo = 0;
        int far = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i + nums[i] <= far)
                continue; // does not advance us
            // in the most recent jump range
            if (i >= lo) {
                lo = i;
                jumps++;
            }
            far = i + nums[i];
        }

        return jumps;
    }
};
