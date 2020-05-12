#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    long long unsigned int i, n, zero = 0;
    scanf("%lld", &n);

    while(n != 0)
    {
        if(!(n & 1))
            zero++;
        n = n >> 1;
    }

    printf("%ld", (long unsigned int)pow(2,zero));
}
