#include <stdio.h>
#include <stdlib.h>


unsigned long long factorial(int n);
int dcm(int x, int y);


int main(int argc, char* argv[])
{
    // int n = atoi(argv[1]);
    // printf("Factorial de %d: %I64d\n", n, factorial(n));

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    printf("DCM(%d, %d) = %d\n", x, y, dcm(x, y));

    return 0;
}


unsigned long long factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}


int dcm(int x, int y)
{
    if(y == 0)
    {
        return x;
    }

    return dcm(y, x % y);
}
