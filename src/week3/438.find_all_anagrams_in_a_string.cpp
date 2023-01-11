#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        // create the 2 counters
        vector<int> s_window(26, 0);
        vector<int> p_window(26, 0);
        int n = p.length();

        // Init p_window
        for (auto c : p) {
            p_window[c]++;
        }
        // Init s_window
        for (int i = 0; i < n; i++) {
            p_window[i]++;
        }

        // slide the windows
        for (int i = 0; i + n < p.length(); i++) {
            if (p_window == s_window) {
                res.push_back(i);
            }
            p_window[i]--;
            p_window[i + n]++;
        }

        return res;
    }
};
