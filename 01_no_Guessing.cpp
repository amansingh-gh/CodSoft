#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Your Machine have selected a number between 1 and 100. Try to guess it!\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
