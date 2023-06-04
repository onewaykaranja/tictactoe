#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;

    cout << "Tiktak toe" << endl;

    while (true) {
        // Draw the board
        drawBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        // Is moov valid?
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        makeMove(board, currentPlayer, row, col);

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        //  Draw
        if (isBoardFull(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch  player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    drawBoard(board);

    return 0;
}

// Draw the board
void drawBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Check winnings
bool checkWin(const vector<vector<char>>& board, char player) {
    // rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // cross
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

// full board ?
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Move
void makeMove(vector<vector<char>>& board, char player, int row, int col) {
    board[row][col] = player;
}