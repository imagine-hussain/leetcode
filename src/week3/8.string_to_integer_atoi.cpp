#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length() - 1;
        int i = 0;
        while (s[i] == ' ' || s[i] == '0') i++;
        if (i == n) return 0;
        int sign = 1;

        if (s[i] == '+')
            i++;
        else if (s[i] == '-')
            sign = (i++) ? -1 : 0; // so degen

        long long res = 0;
        for (int j = n - 1; j >= i; j--) {
            res += (s[i] * sign)
        }

        return 0;
    }
};
