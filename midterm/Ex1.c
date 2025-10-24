#include <stdio.h>
#include <stdlib.h>

/*
This is the power function using iteration
Time complexity O(n)
    */

int digits(int x)
{
    int res;
    while (x > 0) {
        x/=10;
        res += 1;
    }
    return res;
}

int powe(int x, int mu)
{
    int res = 1;
    for (int i = 0; i<mu; i++) {
        res *= x;
    }
    return res;
}

/*
iteration method
Another while to compute the Armstrong number using the power function O(n^2)
The complexity of this function is O(n^2).
    */
int iteration(int x, int dig)
{
    int res = 0;
    int check = x;
    
    for (int i = 0; i < dig; i++) {
        res += powe(x%10,dig);
        x/=10;
    }
    return res;
}

/*
recursion method
Thid method calculate last digit number power to the dig of the number x plus 
the Armstrong number of the number that is x with last digit number divide by 10.
Example: 153-> 3 power to 3 plus Armstrong number of 15
         15-> 5 power to 3 plus Armstrong number of 1.
         1-> 1 power to 3 plus Armstrong number of 0.
The time complexity of this function is O(n^2)
    */
int recursion(int x, int dig)
{
    if (x ==0) {
        return 0;
    } else {
        return powe(x%10,dig) + recursion(x/10,dig);
    }
}

// I use a while to check number of digit: O(n).
int main() {
    int x;
    scanf("%d",&x);
    int y =x;
    int dig = digits(x);
    
    if (recursion(x, dig) == x) {
    // if(iteration(x, dig) == x) {
        printf("%d is a Armstrong number.\n", x);
    } else {
        printf("%d is not a Armstrong number.\n", x);
    }
    return 0;
}
