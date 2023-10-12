// NumberGuess.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numberToGuess, userGuess, attempts = 0;
    const int maxAttempts = 10;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    numberToGuess = (rand() % 100) + 1;

    printf("Welcome to the Number Guessing Game!\n");

    while (1) {
        printf("Enter your guess (1-100): ");
        scanf("%d", &userGuess);
        attempts++;

        if (userGuess == numberToGuess) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (userGuess < numberToGuess) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        if (attempts >= maxAttempts) {
            printf("Sorry, you've run out of attempts. The number was %d.\n", numberToGuess);
            break;
        }
    }

    return 0;
}
