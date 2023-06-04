#include <stdio.h>


// struct to store cpntacts
typedef struct {
    int phone;
    char name[50];
    char address[50];
    char email[30];
} Contact;


// Initializing all global variables here
#define MAX_CONTACTS 100
int option;
int numContacts;
Contact contacts[MAX_CONTACTS];

// Initializing all Functions here
int myStrlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int isSubString(const char* f, const char* l, int debug) {
    int fLen = myStrlen(f);
    int lLen = myStrlen(l);

    if (lLen > fLen) {
        return 0;  // l cannot be longer than f
    }

    for (int i = 0; i <= fLen - lLen; i++) {
        int j;
        for (j = 0; j < lLen; j++) {
            if (f[i + j] != l[j]) {
                break;
            }
        }

        if (j == lLen) {
            if (debug) printf("Got %s, %s. Matched", f, l);
            return 1;  
        }
    }
    if (debug) printf("Got %s, %s. Not Matched", f, l);
    return 0;  
}


 int strcmp(char *s, char *t) 
 { 
    //printf("%s %s", s, t);
    for ( ; *s == *t; s++, t++) 
        if (*s == '\0') 
        return 0; 
    return *s - *t; 
 } 

void printDash(){
    char* dashLine = "----------------------------------------------------------------";
    printf("%s%s\n", dashLine, dashLine);
}


int atoi(char s[]) 
 { 
 int i, n, sign; 
 for (i = 0; s[i]==' '; i++) /* skip white space */ 
 ; 
 sign = (s[i] == '-') ? -1 : 1; 
 if (s[i] == '+' || s[i] == '-') /* skip sign */ 
 i++; 
 for (n = 0; s[i]>='0' && s[i]<='9'; i++) 
 n = 10 * n + (s[i] - '0'); 
 return sign * n; 
 } 


// Used before every scanf to clean the input buffer
void cleanInputBuffer() {
    getchar();
}


// Prints the Home Screen UI
void print_homeUI(){
        printDash();
        printf("CONTACT MANAGEMENT SYSTEM\n");
        printDash();
        printf("0. Quit\n");
        printf("1. Add a new contact\n");
        printf("2. List all contacts\n");
        printf("3. Search contacts\n");
        printf("4. Delete a contact\n");
        printDash();
        printf("Enter option [0-4]\n");
        printDash();
        scanf("%d", &option);
}

// Handles the Exit Routine
void exitHandler(){
    char exitC;
    printf("Are you sure you want to quit?[Y/n]\n");
    scanf(" %c", &exitC);
    switch(exitC){
        case 'Y':
            break;
        case 'n':
            option = 5;
            break;
        default:
            printf("Invalid Prompt. Please Try Again.\n");
            option = 5;
            break;
    }
}

// Handles adding new contacts
void addNew(){
    if (numContacts >= MAX_CONTACTS) {
        printf("Contacts full.Try deleting some contacts\n");
        return;
    }

    Contact newContact;
    cleanInputBuffer();
    printf("Enter name: ");
    scanf("%[^\t\n]",newContact.name);

    cleanInputBuffer();
    printf("Enter phone number: ");
    scanf("%d", &newContact.phone);

    cleanInputBuffer();
    printf("Enter email: ");
    scanf("%s", newContact.email);

    cleanInputBuffer();
    printf("Enter address: ");
    scanf("%[^\t\n]",newContact.address);


    contacts[numContacts++] = newContact;
    printf("Contact added successfully.\n");
}


// Handles listing all the contacts available
// TODO: Pretty print the list
void listAll() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Contact List:\n");
    printDash();
    printf("Name\t\t\tPhone Number\t\t\tEmail\t\t\t\tAddress\n");
    printDash();
    for (int i = 0; i < numContacts; i++) {
        printf("%10s\t\t\t%d\t\t\t%s\t\t\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].address);
    }
    printDash();
}


// Handles the contact search
void searchContacts() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    char searchTerm[20];
    printf("Enter search term: ");
    getchar();
    scanf("%[^\t\n]", searchTerm);

    printf("Search Results:\n");
    printDash();
    printf("Name\t\tPhone Number\t\tAddress\t\tEmail\n");
    printDash();
    for (int i = 0; i < numContacts; i++) {
        if (isSubString(contacts[i].name, searchTerm, 0) == 1 || contacts[i].phone == atoi(searchTerm)) {
            printf("%s\t\t%d\t\t%s\t\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
        }
    }
    printDash();
}


//Handles deleting Contacts
// TODO: When trying to delete a term it enters a stage where the search term is auto filled for some reason. Try and fix it
void deleteContact() {
    if (numContacts == 0) {
        printf("Contact list is empty.\n");
        return;
    }

    char searchTerm[20];
    printf("Enter name or phone number of the contact to delete: ");
    getchar();
    scanf("%[^\t\n]", searchTerm);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        //printf("%d %d\n", contacts[i].phone, atoi(searchTerm));
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
        printDash();
        printf("Did you mean?\n");
        printDash();
        printf("Name\t\tPhone Number\t\tAddress\t\tEmail\n");
        printDash();
        for (int i = 0; i < numContacts; i++) {
            if (isSubString(contacts[i].name, searchTerm, 0) == 1 || contacts[i].phone == atoi(searchTerm)) {
                printf("%s\t\t%d\t\t%s\t\t%s\n", contacts[i].name, contacts[i].phone, contacts[i].address, contacts[i].email);
            }
    }        
    }
}


int main() {
    do {
        cleanInputBuffer();
        print_homeUI();
        //cleanInputBuffer();
        switch(option){
            // Quit
            case 0:
                exitHandler();
                break;
            // Adding a new Contact
            case 1:
                addNew();
                break;
            case 2:
                listAll();
                break;
            case 3:
                searchContacts();
                break;
            case 4:
                deleteContact();
                break;
        }
    } while (option != 0);
    return 0;
}
