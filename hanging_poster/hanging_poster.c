#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    unsigned int wall_points;
    unsigned int length;
    unsigned int diff;
}poster;

int main()
{
    unsigned int n, h, i, j = 0, max = 0, index = 0;
    long double ladder, l;

    scanf("%d %d", &n, &h);
   
    long double *max_height = (long double *)malloc(5 * sizeof(long double));
    poster *pos = (poster *)malloc(n * sizeof(poster));

    for(i = 0; i < n; ++i)
    {
        scanf("%d", &pos[i].wall_points);
    }
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &pos[i].length);
        
        if(pos[i].wall_points > pos[i].length && pos[i].wall_points > h)
            pos[i].diff = pos[i].wall_points - pos[i].length;
        else
            pos[i].diff = 0;
    }
    
    for(i = 0; i < 5; ++i)
    {
        max_height[i] = 0.0;
    }
    
    for(j = 0; j < 5; ++j)
    {
        max = pos[0].diff;
        index = 0;
        for(i = 0; i < n; ++i)
        {
            if(max < pos[i].diff)
            {
                max = pos[i].diff;
                index = i;
            }
        }
        l = pos[index].wall_points - pos[index].length * 0.25 - h;
        max_height[j] = l;
        pos[index].diff = 0;
    }
    
    l = max_height[0];
    for(i = 1; i < 5; ++i)
    {
        if(l < max_height[i])
        {
            l = max_height[i];
        }
    }
    
    if(l > 0.0)
    {
        printf("%0.0f", ceil(l));
    }
    else
    {
        printf("0");
    }

    free(max_height);
    free(pos);
}
