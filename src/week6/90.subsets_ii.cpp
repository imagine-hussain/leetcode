#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int cardinality = 1 << n;
        vector<vector<int>> res;
        for (uint32_t bitset = 0; bitset < cardinality; bitset++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (bitset & (1 << i))
                    subset.push_back(nums[i]);
            }
            res.push_back(subset);
        }

        return res;
    }
};
