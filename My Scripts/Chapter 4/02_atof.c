#include <ctype.h> 
#include <stdio.h> 
#include <math.h>

/* 
atof: convert string s to double 
Handles scientific notation, leading/trailing white space, 
and sign (+/-) characters. 
*/ 
double atof(char s[]) 
{ 
    double val, power; 
    int i, sign; 

    // skip leading white space 
    for (i = 0; isspace(s[i]); i++) 

    // determine sign (+/-) of number 
    sign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-') 
        i++; 

    // process digits before decimal point 
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0'); 

    // process digits after decimal point 
    if (s[i] == '.') 
        i++; 
    for (power = 1.0; isdigit(s[i]); i++) { 
        val = 10.0 * val + (s[i] - '0'); 
        power *= 10; 
    } 

    // handle scientific notation 
    int sci_exp = 0;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        int sci_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (; isdigit(s[i]); i++)
            sci_exp = 10 * sci_exp + (s[i] - '0');
        sci_exp *= sci_sign;
    }

    // calculate final value, including sign and scientific notation
    double result = sign * val / power;
    if (sci_exp != 0)
        result *= pow(10, sci_exp);

    return result;
} 

int main() {
    int jk= atof("  123.45");
    // Test cases
    //printf("%d\n", jk);                  // expected output: 123.450000
    printf("%f\n", atof("-0.006"));        // expected output: -0.006000
    printf("%f\n", atof("6.022e23"));      // expected output: 602200000000000000000000
    printf("%f\n", atof("-5.0e-3"));       // expected output: -0.005000
    printf("%f\n", atof("  +42.0"));       // expected output: 42.000000
    printf("%f\n", atof("  0"));           // expected output: 0.000000

    return 0;
}
