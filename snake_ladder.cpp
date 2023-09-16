#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream> // For file handling

using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

// Function to save the game state
void saveGame(int player1, int player2, int currentPlayer, int gamesPlayed, int player1Wins, int player2Wins, double totalGameDuration) {
    ofstream saveFile("savegame.txt");

    if (saveFile) {
        saveFile << player1 << " " << player2 << " " << currentPlayer << " " << gamesPlayed << " " << player1Wins << " " << player2Wins << " " << totalGameDuration << endl;
        saveFile.close();
        cout << "Game saved successfully." << endl;
    } else {
        cout << "Unable to save the game." << endl;
    }
}

// Function to load the game state
void loadGame(int &player1, int &player2, int &currentPlayer, int &gamesPlayed, int &player1Wins, int &player2Wins, double &totalGameDuration) {
    ifstream loadFile("savegame.txt");

    if (loadFile) {
        loadFile >> player1 >> player2 >> currentPlayer >> gamesPlayed >> player1Wins >> player2Wins >> totalGameDuration;
        loadFile.close();
        cout << "Game loaded successfully." << endl;
    } else {
        cout << "No saved game found." << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    int player1 = 0, player2 = 0;
    int currentPlayer = 1; // Player 1 starts
    string player1Name, player2Name;
    int gamesPlayed = 0, player1Wins = 0, player2Wins = 0;

    double totalGameDuration = 0.0;

    // Input player names
    cout << "Enter the name of Player 1: ";
    cin >> player1Name;
    cout << "Enter the name of Player 2: ";
    cin >> player2Name;

    // Ask if the players want to start a new game or load a saved game
    cout << "Do you want to start a new game (1) or load a saved game (2)? ";
    int choice;
    cin >> choice;

    if (choice == 2) {
        loadGame(player1, player2, currentPlayer, gamesPlayed, player1Wins, player2Wins, totalGameDuration);
    }

    while (true) {
        // Reset the board and currentPlayer for a new game
        player1 = 0;
        player2 = 0;
        currentPlayer = 1;

        // Start a new game
        gamesPlayed++;
        time_t startTime = time(0);

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


            // Add save option during the game
            cout << "Do you want to save the game and exit? (y/n): ";
            char saveChoice;
            cin >> saveChoice;
            if (saveChoice == 'y' || saveChoice == 'Y') {
                saveGame(player1, player2, currentPlayer, gamesPlayed, player1Wins, player2Wins, totalGameDuration);
                return 0;
            }
        }

        // Calculate game duration
        time_t endTime = time(0);
        double gameDuration = difftime(endTime, startTime);
        totalGameDuration += gameDuration;

        // Who is The Winner
        if (player1 >= 100) {
            player1Wins++;
            cout << player1Name << " wins!" << endl;
        } else {
            player2Wins++;
            cout << player2Name << " wins!" << endl;
        }

        // Play another game or save and exit?
        cout << "Do you want to play another game (1) or save and exit (2)? ";
        cin >> choice;
        if (choice == 2) {
            saveGame(player1, player2, currentPlayer, gamesPlayed, player1Wins, player2Wins, totalGameDuration);
            return 0;
        }
    }

    return 0;
}
