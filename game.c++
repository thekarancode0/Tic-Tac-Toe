#include <iostream>
#include <string>
#include <cstdlib> // For system() function

using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string n1, n2;
int row, column;
char token = 'X';
bool tie = false;

void clearConsole() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

void display() {
    cout << "Enter the name of the first player: \n";
    getline(cin, n1);
    cout << "Enter the name of the second player: \n";
    getline(cin, n2);
    cout << n1 << " is player one and will play first\n";
    cout << n2 << " is player two and will play second\n";
}

void displayBoard() {
    cout << "\n\n";
    cout << "     |     |     \n";
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
    cout << "     |     |     \n";
    cout << "\n\n";
}

void inputs() {
    int digit;
    if (token == 'X') {
        cout << n1 << ", please enter a number: ";
        cin >> digit;
    } else if (token == 'O') {
        cout << n2 << ", please enter a number: ";
        cin >> digit;
    }

    if (digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (space[row][column] != 'X' && space[row][column] != 'O') {
            space[row][column] = token;
            token = (token == 'X') ? 'O' : 'X';
        } else {
            cout << "The cell is already occupied! Try again.\n";
            inputs();
        }
    } else {
        cout << "Invalid input! Please enter a number between 1 and 9.\n";
        inputs();
    }
}

bool checkwin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[0][2] == space[2][0])) {
        return true;
    }

    // Check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    display();
    while (!checkwin()) {
        clearConsole();
        displayBoard();
        inputs();
    }

    clearConsole();
    displayBoard();

    if (tie) {
        cout << "It's a draw!\n";
    } else {
        if (token == 'X') {
            cout << n2 << " wins!\n";
        } else {
            cout << n1 << " wins!\n";
        }
    }

    return 0;
}
