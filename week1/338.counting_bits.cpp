#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n+1);

        for (int i = 1; i <= n; ++i)
            vec[i] = vec[i/2] + i % 2;

        return vec;
    }
};
