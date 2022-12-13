#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        x = abs(x);
        int high = highest_pow10_divisible(x);
        int low = 1;

        while (high > low) {
            if ((x/high) % 10 != (x/low) % 10) {
                std::cout << "lo-hi" << low << "  " << high << std::endl;
                return false;
            }

            high /= 10;
            low *= 10;
        }

        return true;
    }

    int highest_pow10_divisible(int x) {
        long long pow10 = 1;
        for (int i = 0; i < INT32_MAX; i++) {
            if ((x / pow10) == 0) {
                return pow10 / 10;
            }
            pow10 *= 10;
        }

        return -1;
    }

};
