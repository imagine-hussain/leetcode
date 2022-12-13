#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        for (auto num : nums)
            res ^= num;
        for (int i = 0; i < nums.size(); i++)
            res^= i;

        return res;
    }
};

