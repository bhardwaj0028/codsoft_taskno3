#include <iostream>
using namespace std;

char gameboard[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
char currentPlayer = 'X';

void drawGameboard() {
    system("clear");
    cout<<endl<<endl; 
    cout << " -----Tic-Tac-Toe Game-----" << endl << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gameboard[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

bool isMoveValid(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || gameboard[row][col] != ' ')
        return false;
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (gameboard[i][0] == currentPlayer && gameboard[i][1] == currentPlayer && gameboard[i][2] == currentPlayer)
            return true;
        if (gameboard[0][i] == currentPlayer && gameboard[1][i] == currentPlayer && gameboard[2][i] == currentPlayer)
            return true;
    }

    if (gameboard[0][0] == currentPlayer && gameboard[1][1] == currentPlayer && gameboard[2][2] == currentPlayer)
        return true;
    if (gameboard[0][2] == currentPlayer && gameboard[1][1] == currentPlayer && gameboard[2][0] == currentPlayer)
        return true;

    return false;
}

bool isGameboardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameboard[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    int row, col;
    bool gameOver = false;

    while (!gameOver) {
        drawGameboard();
        cout<<endl;
        cout << " Turn of player " << currentPlayer << " Now Enter row and column ( as- 1,2 ): ";
        cin >> row >> col;

        if (isMoveValid(row - 1, col - 1)) {
            gameboard[row - 1][col - 1] = currentPlayer;

            if (checkWin()) {
                drawGameboard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (isGameboardFull()) {
                drawGameboard();
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << " Please play a valid move " << endl;
        }
    }

    return 0;
}