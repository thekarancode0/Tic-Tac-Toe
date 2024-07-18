#include <iostream>
#include <string>
#include <cstdlib> //using this for system function to clear screen

using namespace std;

**********************************************************************TIC TAC TOE*************************************************************************************************
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string n1, n2; //TWO PLAYER
int row, column;
char token = 'X';
bool tie = false;


//FUNCTION TO CLEAR THE SCREEN AFTER EACH MOVE
void clearConsole() {
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

//DISPLAY FUNCTION TO TAKE PLAYERS NAME AND CALL ONLY ONE TIME
void display() {
    cout << "Enter the name of the first player: \n";
    getline(cin, n1);
    cout << "Enter the name of the second player: \n";
    getline(cin, n2);
    cout << n1 << " is player one and will play first\n";
    cout << n2 << " is player two and will play second\n";
}

//BOARD DISPLAY
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


//FUNCTION TO TAKE INPUT OF PLAYERS AND THEN REPLACE THESE INPUTS TO BOARD NUMBER IN 'X' OR 'O'
void inputs() {
    int digit;
    if (token == 'X') {
        cout << n1 << ", please enter a number: ";
        cin >> digit;
    } else if (token == 'O') {
        cout << n2 << ", please enter a number: ";
        cin >> digit;
    }

    //TO CHECK PLAYER ENTER VALID DIGIT(1-9)
    if (digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        //FILL THE 'X' OR 'O' IF CELL IS EMPTY
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
    // CHECK ROW AND COLUMN
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    // CHECK DIAGONAL
    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[0][2] == space[2][0])) {
        return true;
    }

    // CHECK FOR TIE
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {  //IF CELL IS NOT 'X' NOR 'O' MEANS THEIR EMPTY CELL TO FILL
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    display();  //CALLING ONLY ONE TIME TO TAKE PLAYERS NAME
    while (!checkwin()) {  //LOOP UNTIL THE CHECK WIN RETURN TRUE--->PLAYER1 WIN OR PLAYER2 WIN OR TIE
        clearConsole();
        displayBoard();
        inputs();
    }

    clearConsole(); //CLEAR EACH TIME
    displayBoard(); //DISPLAYING BOARD FOR NEXT PLAYER

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
