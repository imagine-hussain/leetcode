#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int total = 0;
        for (auto num : nums)
            total += num;

        int n = nums.size();
        int expected = (n * (n + 1)) / 2;

        int diff = expected - total;
    }
};
