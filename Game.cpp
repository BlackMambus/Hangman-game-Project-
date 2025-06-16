#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    string word = " "; // Word to guess
    vector<bool> guessed(word.length(), false);
    int attempts = 9;
    char guess;
    bool won = false;

    cout << "Welcome to Hangman! Try to guess the word." << endl;

    while (attempts > 0 && !won) {
        displayWord(word, guessed);
        cout << "Attempts left: " << attempts << endl;
        cout << "Enter a letter: ";
        cin >> guess;

        bool found = false;
        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == toupper(guess)) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            attempts--;
            cout << "Incorrect guess!" << endl;
        }

        // Check if the player has won
        won = true;
        for (size_t i = 0; i < guessed.size(); i++) {
            if (!guessed[i]) {
                won = false;
                break;
            }
        }
    }

    if (won) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "Game Over! The word was: " << word << endl;
    }

    return 0;
}

