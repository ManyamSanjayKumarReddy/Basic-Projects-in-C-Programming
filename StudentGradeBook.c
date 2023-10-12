// StudentGradeBook.c
#include <stdio.h>

#define MAX_STUDENTS 50

// Function to calculate the average of an array of grades
float calculateAverage(int grades[], int numStudents) {
    float sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += grades[i];
    }
    return sum / numStudents;
}

// Function to find the highest score in an array of grades
int findHighest(int grades[], int numStudents) {
    int highest = grades[0];
    for (int i = 1; i < numStudents; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
    }
    return highest;
}

// Function to find the lowest score in an array of grades
int findLowest(int grades[], int numStudents) {
    int lowest = grades[0];
    for (int i = 1; i < numStudents; i++) {
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    return lowest;
}

int main() {
    int grades[MAX_STUDENTS];
    int numStudents;
    int choice;

    printf("Student Grade Book\n");
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students exceeded.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter the grade for Student %d: ", i + 1);
        scanf("%d", &grades[i]);
    }

    while (1) {
        printf("1. Calculate Average\n");
        printf("2. Find Highest Score\n");
        printf("3. Find Lowest Score\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Average Grade: %.2f\n", calculateAverage(grades, numStudents));
                break;
            case 2:
                printf("Highest Score: %d\n", findHighest(grades, numStudents));
                break;
            case 3:
                printf("Lowest Score: %d\n", findLowest(grades, numStudents));
                break;
            case 4:
                printf("Exiting the Student Grade Book.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
