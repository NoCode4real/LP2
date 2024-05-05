#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check for the column
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // If all queens are placed then return true
        return true;
    }

    for (int col = 0; col < N; ++col) {
        // Check if the queen can be placed on board[row][col]
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, row + 1, N))
                return true;

            // If placing queen in board[row][col] doesn't lead to a solution, then backtrack
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return false;
}

bool solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist";
        return false;
    }

    // Print the solution
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return true;
}

int main() {
    int N;
    cout << "Enter the size of chessboard (N x N): ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
