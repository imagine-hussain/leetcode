#include <iostream>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // want to find i, j, such that `i - j` is maximised.
        // where, `arr[i..j]` contains a maximal amount of (at most k)
        // unique elements
        //

        // go make a window of `k` size; s[0..k]
        // make a unordered_map<char, int> of how many of each character in the
        // window
        //
        // then, there are 2 possibilitie;
        // dp[i] is best u can do with something ending at arr[i]
        // consider some element curr = arr[i]
        // then there are a few opts
        //      - if this curr is already in the hahsmap, we trivally include
        //      it in the best window at no cost
        //      - if this curr is *not* in the map:
        //          - dp[i] ending has:
        //              - consdier the dp[i - 1]
        //              consider the dp[lhs] -> need to slide forwared till not done
        //
        //




        return -1;
    }
};
