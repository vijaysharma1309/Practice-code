#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, query;
    int i, j, index = 0;
    
    scanf("%d", &n);
    
    char *str = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", str);
    scanf("%d", &query);
    
    int interval[query][2];
    for(i = 0; i < query; ++i)
    {
        scanf("%d %d", &interval[i][0], &interval[i][1]);
    }
    
    int alpha[26] = {0};

    for(i = 0; i < query; ++i)
    {
        index = 0; 
        for(j = interval[i][0]; j <= interval[i][1]; ++j)
        {
            if((str[j] > 96) && (index <= (str[j] - 97)) )
            {
                index = str[j] - 97;
                ++alpha[index];
            }
            else if((str[j] < 96) && index <= (str[j] - 65))
            {
                index = str[j] - 65;
                ++alpha[index];
            }
        }

        printf("%d\n", alpha[index]);
    }
    
    free(str);
}
