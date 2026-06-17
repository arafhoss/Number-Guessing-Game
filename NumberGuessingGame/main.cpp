#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool userPlay = true;
bool won = false;
string s_userPlay;
int choice;
int attempts = 0;
high_resolution_clock::time_point start;
high_resolution_clock::time_point endTime;

void stopwatchStart() {
	start = high_resolution_clock::now();
}

void stopwatchStop() {
	endTime = high_resolution_clock::now();
}

long long stopwatchGetDuration() {
	auto duration = duration_cast<seconds>(endTime - start);
	return duration.count();
}

void userPlaying(){
    cout << "Would you like to play again? (Yes/No)";
    cin >> s_userPlay;
    if (s_userPlay == "Yes" || s_userPlay == "yes") {
        userPlay = true;
        choice = 0;
        attempts = 0;
    }

    else {
        userPlay = false;
    }
}


int main() {
    do {
        won = false;
        attempts = 0;
        srand(time(0));
        int number = rand() % 100 + 1;

        cout << "Welcome to the Number Guessing Game!\n";
        cout << "I'm thinking of a number between 1 and 100.\n";

        cout << "Please select the difficulty level:\n";
        cout << "1. Easy (10 chances)\n";
        cout << "2. Medium (5 chances)\n";
        cout << "3. Hard (3 chances)\n";

        do {
            cout << "Enter your choice: ";
            cin >> choice;
        } while (choice < 1 || choice > 3);

        int attemptMax;

        if (choice == 1) attemptMax = 10;
        else if (choice == 2) attemptMax = 5;
        else attemptMax = 3;

        cout << "Lets start the game!\n";
        int guess;

        while (attempts < attemptMax) {
            cout << "Enter your guess: ";
            stopwatchStart();
            cin >> guess;
            stopwatchStop();
            stopwatchGetDuration(); 
            cout << "It took you " << stopwatchGetDuration() << " seconds to guess! \n";
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Numbers only.\n";
                continue;
            }

            attempts++;

            if (guess == number) {
                won = true;
                cout << "Correct! You won in " << attempts << " attempts.\n";
                break;
            }
            else if (guess > number) {
                cout << "Too high!\n";
            }
            else {
                cout << "Too low!\n";
            }

            cout << "Attempts left: " << (attemptMax - attempts) << "\n";
        }
        if (!won) {
            cout << "Game over! The number was " << number << ".\n";
        }

        userPlaying();

    } while (userPlay == true);
    return 0;
}