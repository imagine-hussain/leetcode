#include <vector>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int hi = nums.size() - 1;
        int lo = hi - 1;
        // put lo at the start of the reversed string
        for (; lo >= 0 && nums[lo] >= nums[lo + 1]; lo--);

        if (lo >= 0) {
            int j = nums.size() - 1;
            // find the right-most `nums[j]` that is bigger than nums[i]
            swap(nums[lo], nums[j]);
        }

    }

    /**
     * reverses nums[lo:hi] (inclusive)
     */
    void reverse(vector<int>& nums, int lo, int hi) {
        for (int i = lo; i < hi; i++) {
            int tmp = nums[i];
            nums[i] = nums[hi - i];
            nums[hi - i] = tmp;
        }
    }

};
