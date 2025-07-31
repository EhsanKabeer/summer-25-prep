#include <vector>
#include <iostream>
using namespace std;



static void display(vector<vector<bool>> matrix) {

    for (auto row : matrix) {
        for (auto col : row) {
            if (!col) {
                cout << "X ";
            }
            else {
                cout << "Q ";
            }
        }
        cout << '\n';
    }
}

bool isSafe(vector<vector<bool>> board,int r, int c) {
    //check vertical
    for (int i = 0;i < r;i++) {
        if (board[i][c]) {
            return false;
        }
    }
    //check left diaganol
    int maxLeft = min(r,c);
    for (int i = 0; i <= maxLeft;i++) {
        if (board[r-i][c-i]) {
            return false;
        }
    }
    int i = board.size() - c - 1;
    int maxRight = min(r,i);
    for (int i = 0; i <= maxRight;i++) {
        if (board[r-i][c+i]) {
            return false;
        }
    }
    return true;
}


int queens(vector<vector<bool>> board,int r) {
    if (r == board.size()) {
        display(board);
        cout << '\n';
        return 1;
    }
    int count = 0;
    for (int col = 0;col < board.size();col++) {
        if (isSafe(board,r,col)) {
            board[r][col] = true;
            count += queens(board,r+1);
            //Back tracking since we are changing back to normal after a function call
            board[r][col] = false;
        }
    }

    return count;
}



int main() {
    int n = 5;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    cout << queens(board,0);

    return 0;
}