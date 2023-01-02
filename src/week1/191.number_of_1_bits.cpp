class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += (n >> i) & 0x1;
        }
        return res;
    }
};
