int globalVar;          // External variable, initialized to 0
static int staticVar;   // Static variable, initialized to 0

//Scalar variables (e.g., int, char, long) can be initialized 
//when they are defined by using the equals sign and an expression.
int x = 1;
char squota = '\'';
long day = 1000L * 60L * 60L * 24L; // milliseconds per day

// Initializing arrays. The compiler descides the number of elements
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

char pattern1[] = "ould"; // Array size is 5 (4 characters + terminating null character '\0')
// Equivalent longer initialization
char pattern2[] = { 'o', 'u', 'l', 'd', '\0' }; 

// numbers[3] and numbers[4] will be automatically initialized to 0
int numbers[5] = { 1, 2, 3 };  
// Error: Too many initializers
int values[3] = { 1, 2, 3, 4};



int main() {
    int localVar;        // Automatic variable, undefined initial value
    register int regVar; // Register variable, undefined initial value
    // ...
    for(int i=0;i<5;i++){
        printf("%d", numbers[i]);
    }
    return 0;
}

/*
Automatic variables can be initialized with any expression involving 
previously defined values, even function calls.
*/
int binsearch(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;
    // ...
    return 0;
}
