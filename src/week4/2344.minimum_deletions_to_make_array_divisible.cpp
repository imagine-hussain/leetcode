#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcdd = numsDivide[0];
        for (auto n : numsDivide)
            gcdd = __gcd<int>(gcdd, n);
    }
};
