#include <iostream>
using namespace std;

int isPrime(int num)
{
    if (num < 2) return 0;
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return 0;
    }
    return 1;
}

bool isSpheric(int target, int count, int start = 2)
/*
target: the number to be checked(Begin is n)
count: the number of prime factors left to be found(Begin is 3)
start: the smallest prime factor that can be used(Begin is 2)
*/
{
    if(count == 0) return target == 1;
    if(count == 1) return isPrime(target) && target >= start;
    for(int i = start; i * i <= target; i++)
    {
        if(isPrime(i) && target % i == 0)
        {
            if(isSpheric(target / i, count - 1, i + 1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // int n;
    // cout << "Enter a positive integer: ";
    // cin >> n;
    for(int i = 1; i <= 100; i++)
    {
        if(isSpheric(i, 3))
        {
            cout << i << " ";
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
