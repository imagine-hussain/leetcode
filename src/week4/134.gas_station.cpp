#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_left = 0;
        int start = 0;
        int n = gas.size();

restart:
        while (start < n) {
            for (int offset = 0; offset <= n; offset++) {
                gas_left += gas[(start + offset) % n] - cost[(start + offset) % n];
                if (gas_left < 0) {
                    gas_left = 0;
                    start = start + offset;
                    goto restart;
                }
            }
            return start;
        }

        return -1;
    }


};


