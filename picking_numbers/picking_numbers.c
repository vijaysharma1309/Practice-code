#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n ,i ,j, max = 0, max2 = 0, maximum = 0;
    scanf( "%d", &n );
    int *arr = (int *)malloc( n * sizeof(int) );

    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; ++i)
    {   
        max2 = max;
        max = 0;
        for(j = 0; j < n; ++j)
        {
            if((arr[j] == arr[i] - 1) || arr[j] == arr[i])
                max++;
        }
        if(maximum < max)
            maximum = max;
        
    }

    printf("%d", maximum );
}

