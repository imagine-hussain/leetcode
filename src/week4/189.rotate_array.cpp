#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // rev all
        // let k = 3
        // [1, 2, 3, 4, 5, 6, 7, 8, 9] -- og
        // [9, 8, 7, 6, 5, 4, 3, 2, 1] -- rev all
        // [7, 8, 9, 6, 5, 4, 3, 2, 1] -- rev [0, k)
        // [7, 8, 9, 1, 2, 3, 4, 5, 6] -- rev [k, n)
        reverse_inplace(nums, 0, n - 1);
        reverse_inplace(nums, 0, k - 1);
        reverse_inplace(nums, k, n - 1);

    }

    void reverse_inplace(vector<int>& nums, int lo, int hi) {
        while (lo < hi) {
            swap(nums, lo, hi);
            lo++;
            hi--;
        }
    }

    inline void swap(vector<int>& nums, int lo, int hi) {
        int tmp = nums[hi];
        nums[hi] = nums[lo];
        nums[lo] = tmp;
    }

};
