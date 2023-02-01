#include <vector>
#include <iostream>

using namespace std;

class Token {
public:
    enum TokenType {
        Operation,
        Numeric
    };

    int value;
    char operation;
    TokenType type;

};

class Solution {
public:
    int calculate(string s) {
        vector<Token> tokens = tokenise(s);


        return -1;
    }


    vector<Token> tokenise(string s) {
        int lo = 0;
        int hi = 0;

        vector<Token> tokens;

        while (true) {
            while (hi < s.size() && s[hi] != '*' && s[hi] != '+' && )
        }

        return tokens;
    }

};
