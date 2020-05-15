#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int match(char *num, char *ans ,int n)
{
    int i, j, index;

    for(index = 1; index <= n; ++index)
    {
        int z = 0;
        
        //always doing a shift of 1
        int arr2[1];
        for(j = 0; j < 1; ++j)
        {
            arr2[j] = num[j];
        }
        for(j = 1; j < n; ++j)
        {
            num[j-1] = num[j];
        }
        for(j = n-1; j < n; ++j)
        {
            num[j] = arr2[z++];
        }
        
        if(strcmp(num, ans) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int carry = 0, i, j, len = 0, flag = 0;
    char num[64];
    char *copy = NULL, *ans = NULL;

    scanf("%s", num);
    
    len = strlen(num);

    ans = (char *)malloc((len+1) * sizeof(char));
    copy = (char *)malloc((len+1) * sizeof(char));
    
    strcpy(copy, num);
    copy[len] = '\0';
    ans[len] = '\0';

    for(i = 1; i <= len; ++i)
    {
        carry = 0;
        for(j = len-1; j >= 0; --j)
        {
            ans[j] = ((carry + (num[j]-48) * i) % 10) + 48;
            carry = (carry + (num[j]-48) * i) / 10;
        }

        if(!match(num, ans, len))
        {
            flag = 1;
            break;
        }
        strcpy(num, copy);
    }

    if(flag)
    {
        printf("%s is not cyclic\n", copy);
    }
    else
    {
        printf("%s is cyclic\n", copy);
    }
    
    free(copy);
    free(ans);
}
