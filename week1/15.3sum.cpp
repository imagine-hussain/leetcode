#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> results;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size(); k++) {
            int target = -nums[k];
            vector<vector<int>> newer;

        }

        return results;
    }
};
