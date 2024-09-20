/* Create a file to enter two integer numbers and output to screen of console: sum and difference of two numbers */

#include <stdio.h>

int main(){
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    int sum = a + b;
    int diff = a - b;

    printf("Sum(a,b) = %d\n", sum);
    printf("Diff(a,b) = %d\n", diff);

    return 0;
}