/* Declare two integer variables a and b and assign them with 5 and 10 and after that exchange their values 
by using some programming logic. Print the variable values before and after the exchange*/

#include <stdio.h>

int main(){
    int a = 5;
    int b = 10;

    printf("Before: \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    int temp = a;
    a = b;
    b = temp;

    printf("After: \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}