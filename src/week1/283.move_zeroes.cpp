#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroes++;
                continue;
            }
            nums[i - zeroes] = nums[i];
        }
        int end = nums.size();
        for (int i = 1; i <= zeroes; i++)
            nums[end - i] = 0;
    }
};
