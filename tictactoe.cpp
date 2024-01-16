#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

void displayBoard(const char board[]);
void playerMove(char board[]);
void computerMove(char board[]);
bool checkWinner(const char board[]);
bool checkTie(const char board[]);

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    cout << "Welcome to Tic Tac Toe!" << endl;

    // Main game loop
    while (true) {
        displayBoard(board);

        playerMove(board);
        if (checkWinner(board)) {
            cout << "YOU WIN!" << endl;
            break;
        } else if (checkTie(board)) {
            cout << "It's a tie!" << endl;
            break;
        }

        computerMove(board);
        if (checkWinner(board)) {
            cout << "YOU LOSE!" << endl;
            break;
        } else if (checkTie(board)) {
            cout << "It's a tie!" << endl;
            break;
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}

// Function to display the Tic Tac Toe board
void displayBoard(const char board[]) {
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "\n";
}

// Function to get the player's move
void playerMove(char board[]) {
    int position;

    do {
        cout << "Enter a position (1-9) to place your marker: ";
        cin >> position;

        // Input validation
        if (position < 1 || position > 9 || board[position - 1] != ' ') {
            cout << "Invalid position. Please try again." << endl;
        }
    } while (position < 1 || position > 9 || board[position - 1] != ' ');

    board[position - 1] = 'X';  // Place the player's marker
}

// Function to get the computer's move
void computerMove(char board[]) {
    srand(time(NULL));  // Seed the random number generator
    int position;

    do {
        position = rand() % 9;
    } while (board[position] != ' ');  // Find an empty spot

    board[position] = 'O';  // Place the computer's marker
}

// Function to check if there's a winner
bool checkWinner(const char board[]) {
    // Check rows, columns, and diagonals for a winning combination
    for (int i = 0; i < 3; i++) {  // Check rows
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) {
            std::cout << "YOU WIN!\n";
            return true;
        } else if (board[i * 3] == computer && board[i * 3 + 1] == computer && board[i * 3 + 2] == computer) {
            std::cout << "YOU LOSE!\n";
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {  // Check columns
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            std::cout << "YOU WIN!\n";
            return true;
        } else if (board[i] == computer && board[i + 3] == computer && board[i + 6] == computer) {
            std::cout << "YOU LOSE!\n";
            return true;
        }
    }   

    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player || board[2] == player && board[4] == player && board[6] == player) {
        std::cout << "YOU WIN!\n";
        return true;
    } else if (board[0] == computer && board[4] == computer && board[8] == computer || board[2] == computer && board[4] == computer && board[6] == computer) {
        std::cout << "YOU LOSE!\n";
        return true;
    }

    return false;  // No winner yet
}

// Function to check if the game is a tie
bool checkTie(const char board[]) {
    for(int i = 0; i < 9; i++){
        if(board[i] == ' '){
            return false;
        }
    }
    std::cout << "It's a Tie!\n";
    return true;
}
