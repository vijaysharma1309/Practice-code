#include <stdio.h>

int main()
{
    int s,t,n,m,a,b;
    int i,j,count1=0,count2=0;

    scanf("%d %d", &s, &t);
    scanf("%d %d", &a, &b);
    scanf("%d %d", &m, &n);
    int s1[m], s2[n];

    for(i = 0; i < m; ++i)
    {
        scanf("%d", &s1[i]);
    }
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &s2[i]);
    }

    for(i = 0; i < m; ++i)
    {
        if((s1[i] + a) >= s && (s1[i] + a) <= t)
            count1++;
    }
    for(i = 0; i < n; ++i)
    {
        if((s2[i] + b) >= s && (s2[i] + b) <= t)
            count2++;
    }
    printf("%d\n%d", count1, count2);
}

