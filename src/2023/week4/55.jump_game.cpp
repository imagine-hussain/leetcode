#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, max_idx = 0; i < nums.size(); i++) {
            if (i > max_idx) return false;
            max_idx = max(max_idx, i + nums[i]);
        }
        return true;
    }
};

