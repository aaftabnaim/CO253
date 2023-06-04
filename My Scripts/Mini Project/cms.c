#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    int phone;
    char name[20];
    char address[50];
    char email[30];
} Contact;

Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }
    
    Contact newContact;

    printf("Enter name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';  // Remove the newline character

    printf("Enter phone number: ");
    scanf("%d", &newContact.phone);

    printf("Enter email: ");
    scanf("%s", newContact.email);

    printf("Enter address: ");
    scanf("%s", newContact.address);

    contacts[numContacts++] = newContact;
    printf("Contact added successfully.\n");
}

void listContacts() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Contact List:\n");
    printf("-----------------------------------------------------------\n");
    printf("Name\t\t\tPhone Number\t\t\tAddress\t\t\tEmail\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s\t\t\t%d\t\t\t%s\t\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
    }
    printf("-----------------------------------------------------------\n");
}

void searchContacts() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    char searchTerm[20];
    printf("Enter search term: ");
    scanf("%s", searchTerm);

    printf("Search Results:\n");
    printf("-----------------------------------------------------------\n");
    printf("Name\t\tPhone Number\t\tAddress\t\tEmail\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchTerm) == 0 || contacts[i].phone == atoi(searchTerm)) {
            printf("%s\t\t%d\t\t%s\t\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
        }
    }
    printf("-----------------------------------------------------------\n");
}

void deleteContact() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    char searchTerm[20];
    printf("Enter name or phone number of the contact to delete: ");
    scanf("%s", searchTerm);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchTerm) == 0 || contacts[i].phone == atoi(searchTerm)) {
            found = 1;
            for (int j = i; j < numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            numContacts--;
            printf("Contact deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int option;

    do {
        printf("\nCONTACT MANAGEMENT SYSTEM\n");
        printf("0. Quit\n");
        printf("1. Add a new contact\n");
        printf("2. List all contacts\n");
        printf("3. Search contacts\n");
        printf("4. Delete a contact\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContacts();
                break;
            case 4:
                deleteContact();
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);

    return 0;
}
