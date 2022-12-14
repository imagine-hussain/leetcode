#include <vector>

using namespace std;

#define SQUARE(x) ((x * x))

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int pos = nums.size() - 1;
        int neg = 0;
        vector<int> res(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) {
            int out = 0;
            if (nums[neg] <= 0 && -nums[neg] >= nums[pos]) {
                res[i] = nums[neg];
                neg++;
            } else {
                res[i] = SQUARE(nums[pos]);
                pos--;
            }
        }

        for (;;) {

        }


        return res;
    }
};
