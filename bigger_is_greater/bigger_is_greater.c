#include<stdio.h>
#include<string.h>

void swap_char(char *s1, char *s2)
{
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

char *bigger_is_greater(char *str, int len)
{
    int i, j, k = 0;
    char final_str[len];
    
    for(i = len-1; i > 0; --i)
    {
        if(str[i] <= str[i-1])
        {
            continue;
        }
        break;
    }

    if(i != 0)
    {
        for(j = i; j < len; ++j)
        {
            if(str[i-1] < str[j])
            {
                continue;
            }
            break;
        }
        swap_char(&str[j-1], &str[i-1]);
        for(j = 0; j < i; ++j)
        {
            final_str[k++] = str[j];
        }
        for(j = len-1; j >= i; --j)
        {
            final_str[k++] = str[j];
        }
        strncpy(str, final_str, len);

        return str;
    }
    
    return "no answer";
}

int main()
{
    int t, len = 0;
    char str[104];

    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str);
        len = strlen(str);
        printf("%s\n", bigger_is_greater(str, len));
    }
}

