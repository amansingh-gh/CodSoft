#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    bool gameFinished;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X'), gameFinished(false) {}

    void displayBoard() {
        cout << "   1   2   3" << endl;
        cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "  ---|---|---" << endl;
        cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "  ---|---|---" << endl;
        cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << endl;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
        }

        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;

        while (!gameFinished) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row column): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameFinished = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameFinished = true;
            }

            switchPlayer();
        }
    }
};

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        TicTacToe game;
        game.play();

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}