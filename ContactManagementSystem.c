// ContactManagementSystem.c
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure to represent a contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

// Function to display a contact
void displayContact(struct Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Phone: %s\n", contact.phone);
    printf("Email: %s\n", contact.email);
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    while (1) {
        printf("Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numContacts < MAX_CONTACTS) {
                    struct Contact newContact;
                    printf("Enter Name: ");
                    scanf(" %[^\n]", newContact.name);
                    printf("Enter Phone: ");
                    scanf(" %[^\n]", newContact.phone);
                    printf("Enter Email: ");
                    scanf(" %[^\n]", newContact.email);

                    contacts[numContacts] = newContact;
                    numContacts++;
                    printf("Contact added successfully.\n");
                } else {
                    printf("Contact limit reached. Cannot add more contacts.\n");
                }
                break;
            case 2:
                if (numContacts == 0) {
                    printf("No contacts available.\n");
                } else {
                    printf("Contacts List:\n");
                    for (int i = 0; i < numContacts; i++) {
                        printf("Contact %d:\n", i + 1);
                        displayContact(contacts[i]);
                    }
                }
                break;
            case 3:
                printf("Exiting the Contact Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
