#include <vector>

using std::vector;
using std::min;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int hi = nums.size() - 1;
        int lo = 0;

        int  i = 0;
        while (hi > lo + 1) {
            int mid = (lo + hi) / 2;
            if (nums[lo] > nums[mid])
                hi = mid;
            else
                lo = mid;
        }
        return min(min(nums[0], nums[nums.size() - 1]), min(nums[hi], nums[lo]));
    }
};
