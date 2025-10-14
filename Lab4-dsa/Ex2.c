#include <stdio.h>
/*
checkSphenic(x):
    checkSpenic(prime1) 
    checkSpenic(prime1 -1)
    checkSpenic(prime1 -2)
*/

int isPrime(int num)
{
    if (num < 2) 
        return 0;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return 0;
    }
    return 1;
}
int primes[3] = {2, 3, 5};
void isSpheric(int x)
{
    while(primes[0]*primes[1]*primes[2] <= x) {
        for(int i = 2; i >= 0; i--) {
            while(!isPrime(primes[i])) {
                continue;
            }
            primes[i]+=1;
            printf("%d\n",primes[0]*primes[1]*primes[2]);
        }
    }
}

/*
Time complexity analysis:
1.Function isPrime(int num):
   - The function checks if a number is prime by testing divisibility from 2 up to the square root of the number.
   - In the worst case, this takes O(sqrt(num)) time.
2.Function isSpheric_Recursive(int target, int count, int start):
    - The function recursively tries to factos target into exacly count(here count = 3) prime factos,each >= start.
    - At each recursion level, it loops over all possible divisors i from start to sqrt(target).
    - And for each prime i that divides target, it makes a recursive call with target / i and count - 1.
    - The depth of the recursion is count, which is 3 in this case.
    - At each level, in the worst case, we may have to check up to O(sqrt(target)) divisors.
    - Therefore, the time complexity can be approximated as O((sqrt(n))^count) 
    - For count = 3, this becomes O(n^(3/2)).
==> Time complexity of the algorithm is O(n^(3/2) * sqrt(n)) = O(n^2) in the worst case.
*/

int main() {
    // int x;
    // scanf("%d", &x);    
    isSpheric(100);
    return 0;
}
