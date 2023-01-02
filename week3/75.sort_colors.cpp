#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counter(3, 0);
        for (auto num : nums) counter[num]++;
        int curr_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (counter[curr_index] == 0) {
                curr_index++;
            }
            nums[i] = curr_index;
            counter[curr_index]--;
        }
    }
};
