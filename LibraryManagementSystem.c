// LibraryManagementSystem.c
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to represent a book
struct Book {
    char title[100];
    char author[50];
    int year;
};

// Function to display a book
void displayBook(struct Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
}

int main() {
    struct Book library[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    while (1) {
        printf("Library Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search by Title\n");
        printf("4. Search by Author\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numBooks < MAX_BOOKS) {
                    struct Book newBook;
                    printf("Enter Title: ");
                    scanf(" %[^\n]", newBook.title);
                    printf("Enter Author: ");
                    scanf(" %[^\n]", newBook.author);
                    printf("Enter Year: ");
                    scanf("%d", &newBook.year);

                    library[numBooks] = newBook;
                    numBooks++;
                    printf("Book added successfully.\n");
                } else {
                    printf("Library is full. Cannot add more books.\n");
                }
                break;
            case 2:
                if (numBooks == 0) {
                    printf("Library is empty.\n");
                } else {
                    printf("Books in the Library:\n");
                    for (int i = 0; i < numBooks; i++) {
                        printf("Book %d:\n", i + 1);
                        displayBook(library[i]);
                    }
                }
                break;
            case 3:
                if (numBooks == 0) {
                    printf("Library is empty.\n");
                } else {
                    char searchTitle[100];
                    printf("Enter the title to search: ");
                    scanf(" %[^\n]", searchTitle);
                    int found = 0;
                    for (int i = 0; i < numBooks; i++) {
                        if (strcmp(searchTitle, library[i].title) == 0) {
                            displayBook(library[i]);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Book not found with that title.\n");
                    }
                }
                break;
            case 4:
                if (numBooks == 0) {
                    printf("Library is empty.\n");
                } else {
                    char searchAuthor[50];
                    printf("Enter the author to search: ");
                    scanf(" %[^\n]", searchAuthor);
                    int found = 0;
                    for (int i = 0; i < numBooks; i++) {
                        if (strcmp(searchAuthor, library[i].author) == 0) {
                            displayBook(library[i]);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Book not found by that author.\n");
                    }
                }
                break;
            case 5:
                printf("Exiting the Library Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
