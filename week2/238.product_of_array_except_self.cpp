#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> lhs(n, 1);
        vector<int> rhs(n, 1);

        for (int i = 1; i < n; i++) {
            lhs[i] = lhs[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            rhs[i] = rhs[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            lhs[i] = lhs[i] * rhs[i];
        }

        return lhs;
    }

};
