// HangmanGame.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 6
#define WORDS_COUNT 10

const char* words[] = {
    "apple",
    "banana",
    "chocolate",
    "elephant",
    "giraffe",
    "hamburger",
    "keyboard",
    "landscape",
    "pineapple",
    "watermelon"
};

// Function to randomly select a word from the list
const char* getRandomWord() {
    int randomIndex = rand() % WORDS_COUNT;
    return words[randomIndex];
}

int main() {
    srand(time(0));
    const char* wordToGuess = getRandomWord();
    int wordLength = strlen(wordToGuess);
    char guessedWord[wordLength];
    int attempts = 0;

    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    printf("Welcome to Hangman!\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("Word to Guess: %s\n", guessedWord);
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (wordToGuess[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            attempts++;
            printf("Incorrect guess. Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
        }

        if (strcmp(wordToGuess, guessedWord) == 0) {
            printf("Congratulations! You've guessed the word: %s\n", wordToGuess);
            break;
        }
    }

    if (attempts >= MAX_ATTEMPTS) {
        printf("You're out of attempts! The word was: %s\n", wordToGuess);
    }

    return 0;
}
