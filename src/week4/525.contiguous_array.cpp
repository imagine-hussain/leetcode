#include <vector>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //

        int n = nums.size();
        vector<int> from_lhs(n);
        vector<int> from_rhs(n);

        // sums[i] := number of 1s in nums[..=i]
        vector<int> sums = init_cumulative(nums);





        return -1;
    }

    vector<int> init_cumulative(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size());
        res[0] = nums[0];
        for (int i = 0; i < n; i++)
            res[i] = nums[i] + res[i - 1];

        return res;
    }

};
