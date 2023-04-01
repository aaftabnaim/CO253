/*
4. Find the Factor

Determine the factors of a number(i.e. all positive integer values that
evenly divide into a number) and then return the pth element of the
list, sorted ascending. If there is no pth element, return 0.
Example
The factors of 20 in ascending order are {1, 2, 4, 5, 10, 20}. Using 1-
based indexing, if p=3, then 4 is returned. If p > 6, 0 would be
returned.
Function Description
Complete the function pthFactor in the editor below.
pthFactor has the following parameters:
• intm the integer whose factors are to be found
• intp:the index of the factor to be returned
Returns:
int: the long integer value of the pth integer of n or, if there is no
factor at that, then 0 is returned
Constraints
1<= n <= 1015
1<= p <= 109

*/

long pthFactor(int n, int p) {
    
    int facNum = 1;
    int isDiv;
    
    for(int f=1; f<=n;f++){
        isDiv = n%f;
        if(isDiv==0){
            if(facNum==p){
                return f;
             }
             else{
                facNum++;
             }
        }

    }
    return 0;

}

