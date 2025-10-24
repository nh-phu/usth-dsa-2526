#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
    return(x==0)? y : gcd(x % y, x);
}

int main() {
    int x[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};

    return 0;
}
