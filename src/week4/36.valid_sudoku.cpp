#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 0; i++)
            if (!(validate_row(board, i) && validate_col(board, i)) && validate_square(board, i))
                return false;

        return true;
    }


    bool validate_square(vector<vector<char>>& board, int i) {
        // 0 1 2
        // 3 4 5
        // 6 7 8
        // row := i / 3
        // col := i % 3
        uint16_t res = 0;
        int start_row = i / 3;
        int start_col = i % 3;
        for (int k = 0; k < 9; k++) {
            int row = k / 3;
            int col = k % 3;
            if (board[row][col] == '.')
                continue;
            uint16_t val = 1 << (board[row][col] - '0');
            if ((val ^ res) != (val | res))
                return false;
            res |= val;
        }

        return true;
    }

    bool validate_col(vector<vector<char>>& board, int j) {
        uint16_t res = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.')
                continue;
            uint16_t val = 1 << (board[i][j] - '0');
            if ((val ^ res) != (val | res))
                return false;
            res |= val;
        }
        return true;
    }


    bool validate_row(vector<vector<char>>& board, int i) {
        uint16_t res = 0;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.')
                continue;
            uint16_t val = 1 << (board[i][j] - '0');
            if ((val ^ res) != (val | res))
                return false;
            res |= val;
        }
        return true;
    }

};
