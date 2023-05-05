#include <stdio.h> 

void switch_eg1();

int main() {
    //switch_eg1();
    switch_eg2();
    return 0;
}

void switch_eg1(){
    int c, i, nwhite, nother;
    // ndigit array will be used to store the count of digits from 0 to 9.
    int ndigit[10];
    
    nwhite = nother = 0;
    for (i = 0; i < 10; i++) {
        // Initializing each element of ndigit array to 0.
        ndigit[i] = 0;
    }
    
    // Read input from standard input until end of file (EOF) is reached.
    while ((c = getchar()) != EOF) {
        switch (c) {
            // If the character is a digit, increment the corresponding element in ndigit array.
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c-'0']++;
                break;
            // If the character is a whitespace character, increment the count of white space.
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            // For all other characters, increment the count of other characters.
            default:
                nother++;
                break;
        }
    }
    
    // Print the counts of digits, white space and other characters.
    printf("digits =");
    for (i = 0; i < 10; i++) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
    
}


int switch_eg2() {
   char letter = 'C';
   
   switch (letter) {
      case 'A':
         printf("The letter is A.\n");
         //break;
      case 'B':
         printf("The letter is B.\n");
         break;
      case 'C':
         printf("The letter is C.\n");
         //break;
      default:
         printf("The letter is not A, B, or C.\n");
         break;
   }
   
   return 0;
}
