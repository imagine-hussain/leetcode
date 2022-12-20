#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums, 0, nums.size() - 1);
        return (pivot != -1) ? bsearch(nums, target, 0, nums.size(), pivot) : -1;
    }
private:
    int findPivot(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return -1;
        int mid = (lo + hi) / 2;

        if (mid == hi) return mid + 1;
        if (nums[mid] > nums[mid + 1]) return mid + 1;

        return (nums[mid] < nums[lo]) ?
            findPivot(nums, lo, mid - 1) : findPivot(nums, mid + 1, hi);
    }

    int bsearch(vector<int>& nums, int target, int lo, int hi, int pivot) {
        if (hi < lo || lo < 0) return -1;

        int mid = (lo + hi) / 2;
        int realmid = (mid + pivot) % nums.size();

        if (nums[realmid] < target) return bsearch(nums, target, mid + 1, hi, pivot);
        if (nums[realmid] > target) return bsearch(nums, target, lo, mid - 1, pivot);
        return realmid;
    }
};

