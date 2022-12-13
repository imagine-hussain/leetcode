#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 31; i >= 0; i--) {
            res |= ((n >> i) & (0x1)) << (31 - i);
        }

        return res;
    }
};
