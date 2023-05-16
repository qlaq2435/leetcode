/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
   private:
    bool row[9][9];
    bool col[9][9];
    bool block[3][3][9];

   public:
    // void printBoard(vector<vector<char>> board) {
    //     std::cout << "------------" << std::endl;

    //     for (int i = 0; i < 9; i++) {
    //         for (int j = 0; j < 9; j++) {
    //             std::cout << board[i][j] << " ";
    //         }
    //         std::cout << std::endl;
    //     }
    // }

    bool fillSudoku(vector<vector<char>>& board) {
        // printBoard(board);
        bool sudokuFilled = true;
        int x = -1, y = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    sudokuFilled = false;
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if (sudokuFilled) {
            return true;
        }

        for (int k = 1; k <= 9; k++)
            if (!col[y][k - 1] && !row[x][k - 1] && !block[x / 3][y / 3][k - 1]) {
                char n = k + '0';
                col[y][k - 1] = true;
                row[x][k - 1] = true;
                block[x / 3][y / 3][k - 1] = true;
                board[x][y] = n;
                if (fillSudoku(board)) return true;
                col[y][k - 1] = false;
                row[x][k - 1] = false;
                block[x / 3][y / 3][k - 1] = false;
            }

        board[x][y] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset((wchar_t*)row, false, sizeof(row));
        memset((wchar_t*)col, false, sizeof(col));
        memset((wchar_t*)block, false, sizeof(block));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0' - 1;
                    row[i][n] = col[j][n] = block[i / 3][j / 3][n] = true;
                }
            }
        }
        fillSudoku(board);
        // printBoard(board);
    }
};

// @lc code=end
