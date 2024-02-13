#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> seen;

        int curr_len = 0;
        int global_len = 0;


        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            // Remove from lhs until no repeats
            while (seen.find(s[i]) != seen.end()) {
                seen.erase(s[i - curr_len]); // end element removed
                curr_len--;
            }
            seen.insert(pair<char, int>(s[i], 1));
            curr_len++;
            global_len = max(curr_len, global_len);
        }

        return global_len;
    }
};

int main (int argc, char *argv[])
{
    Solution x;
    string input = "abcabcbb";
    int res = x.lengthOfLongestSubstring(input);
    std::cout << "res1:  " << res << std::endl;

    res = x.lengthOfLongestSubstring("bbbbb");
    std::cout << "res2:  " << res << std::endl;

    res = x.lengthOfLongestSubstring("pwwkew");
    std::cout << "res3:  " << res << std::endl;

    res = x.lengthOfLongestSubstring("");
    std::cout << "res4:  " << res << std::endl;

    return 0;
}

