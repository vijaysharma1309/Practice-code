#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isValid(char *str, int n)
{
    int i, count1 = 0, count2 = 0;
    int val = 0, min = 0, num_char = 0;
    int alpha[26] = {0};

    for(i = 0; i < n; ++i)
    {
        alpha[str[i] - 97] += 1;
    }
    
    for(i = 0; i < 26; ++i)
    {
        if(alpha[i])
        {
            ++num_char;
        }
    }
    
    min = alpha[str[0] - 97];
    for(i = 0; i < 26; ++i)
    {
        if(alpha[i] && (min > alpha[i] || min == 1) && alpha[i] != 1)
        {
            min = alpha[i];
        }
    }

    for(i = 0; i < 26; ++i)
    {
        if(alpha[i])
        {
            alpha[i] = abs(min - alpha[i]);
            if(alpha[i] == 1)
            {
                ++count1;
            }
            if(alpha[i] > 1)
            {
                ++count2;
            }
        }
    }

    if(count1 > 1 || count2 > 1)
        return 0;
    
    if((n % num_char != 0) && count2 == 1)
        return 0;

    return 1;
}

int main()
{
    int i, len = 0;
    char str[102400];
    scanf("%s", str);
    
    len = strlen(str);
    if(isValid(str, len)) 
    {
        printf("YES\n");
    }
    else 
    {
        printf("NO\n");
    }
}
