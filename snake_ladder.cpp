#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(0)); // Seed for random number generation
    int player1 = 0, player2 = 0;
    int currentPlayer = 1; // Player 1 starts
    string player1Name, player2Name;

    // Input player names
    cout << "Enter the name of Player 1: ";
    cin >> player1Name;
    cout << "Enter the name of Player 2: ";
    cin >> player2Name;

    while (player1 < 100 && player2 < 100) {
        // Switch players
        if (currentPlayer == 1) {
            cout << player1Name << "'s turn. Press Enter to roll the dice...";
            cin.ignore();
            cin.get();
            int dice = rollDice();
            cout << "You rolled a " << dice << endl;
            player1 += dice;
            cout << player1Name << " is now at position " << player1 << endl;
            currentPlayer = 2;
        } else {
            cout << player2Name << "'s turn. Press Enter to roll the dice...";
            cin.ignore();
            cin.get();
            int dice = rollDice();
            cout << "You rolled a " << dice << endl;
            player2 += dice;
            cout << player2Name << " is now at position " << player2 << endl;
            currentPlayer = 1;
        }

        // Check for snakes and ladders
        if (player1 == 14) {
            player1 = 3;
            cout << player1Name << " got a ladder! Climbing to position 3." << endl;
        } else if (player1 == 27) {
            player1 = 19;
            cout << player1Name << " got a ladder! Climbing to position 19." << endl;
        } else if (player1 == 35) {
            player1 = 9;
            cout << player1Name << " got a snake! Sliding down to position 9." << endl;
        } else if (player1 == 50) {
            player1 = 5;
            cout << player1Name << " got a snake! Sliding down to position 5." << endl;
        } else if (player1 == 70) {
            player1 = 48;
            cout << player1Name << " got a snake! Sliding down to position 48." << endl;
        } else if (player1 == 77) {
            player1 = 32;
            cout << player1Name << " got a snake! Sliding down to position 32." << endl;
        } else if (player1 == 86) {
            player1 = 56;
            cout << player1Name << " got a snake! Sliding down to position 56." << endl;
        } else if (player1 == 99) {
            player1 = 21;
            cout << player1Name << " got a snake! Sliding down to position 21." << endl;
        }

        if (player2 == 14) {
            player2 = 3;
            cout << player2Name << " got a ladder! Climbing to position 3." << endl;
        } else if (player2 == 27) {
            player2 = 19;
            cout << player2Name << " got a ladder! Climbing to position 19." << endl;
        } else if (player2 == 35) {
            player2 = 9;
            cout << player2Name << " got a snake! Sliding down to position 9." << endl;
        } else if (player2 == 50) {
            player2 = 5;
            cout << player2Name << " got a snake! Sliding down to position 5." << endl;
        } else if (player2 == 70) {
            player2 = 48;
            cout << player2Name << " got a snake! Sliding down to position 48." << endl;
        } else if (player2 == 77) {
            player2 = 32;
            cout << player2Name << " got a snake! Sliding down to position 32." << endl;
        } else if (player2 == 86) {
            player2 = 56;
            cout << player2Name << " got a snake! Sliding down to position 56." << endl;
        } else if (player2 == 99) {
            player2 = 21;
            cout << player2Name << " got a snake! Sliding down to position 21." << endl;
        }
    }

    // Determine the winner
    if (player1 >= 100) {
        cout << player1Name << " wins!" << endl;
    } else {
        cout << player2Name << " wins!" << endl;
    }

    return 0;
}
