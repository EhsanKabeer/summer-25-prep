#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int r = -1;
        int c = -1;

        bool boardFull = true;
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == '.') {
                    r = i;
                    c = j;
                    boardFull = false;
                    break;
                }
            }
            if (!boardFull) {
                break;
            }
        }


        if (!boardFull) {
            for (int i = 1;i <= 9;i++) {
                char num = i + '0';
                if (isSafe(board,r,c,num)) {
                    board[r][c] = num;
                    solveSudoku(board);
                    board[r][c] = '.';
                }
            }
        }
        else {
            display(board);
            return;
        }

    }

private:
    static void display(const vector<vector<char>>& board) {
        for (auto row : board) {
            for (auto num : row) {
                cout << num << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    static bool isSafe(const vector<vector<char>>& board, int r,int c,char num) {
        //Check row
        for (int i = 0;i < 9;i++) {
            if (board[r][i] == num) {
                return false;
            }
        }

        //check Column
        for (int i = 0;i < 9;i++) {
            if (board[i][c] == num) {
                return false;
            }
        }

        //Check section
        const int startRow = r - (r%3);
        const int startCol = c - (c%3);
        for (int i = 0; i < 3;i++) {
            if (board[startRow][startCol+i] == num) {
                return false;
            }
            if (board[startRow+1][startCol+i] == num) {
                return false;
            }
            if (board[startRow+2][startCol+i] == num) {
                return false;
            }
        }
        return true;
    }
};


int main () {
    Solution test;
    vector<vector<char>> SudokuBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    test.solveSudoku(SudokuBoard);

    return 0;
}