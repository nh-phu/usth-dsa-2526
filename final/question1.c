#include <stdio.h>
#include <stdlib.h>

int power(int a, int n)
{
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return power(a, n/2) * power(a, n/2);
    } else {
        return a * power(a, (n - 1)/2) * power(a, (n - 1)/2);
    }
}
/*
if n == 0, return 1
else the recursion is in the power n whether is even or odd. Both n is divide by
2, so the complexity is log_2(n).
The time complexity is O(log_2(n))
You can tell this is not AI because i am bad at explaning and complexity.
*/

int main() {
    int a = 5;
    int n = 3;
    printf("Result: %d\n", power(a, n));
    return 0;
}
