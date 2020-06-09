#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t, i, j, k, l, a, b, flag = 0, start = 0;
    int I, J, max_col = 0, max_row = 0, count = 0, count_row = 0;
    int q;
    scanf("%d", &t);

    int R[t], C[t], r[t],c[t];
    char g[t][1024][1024];
    char p[t][1024][1024];

    for(i = 0; i < t; ++i)
    {
        scanf("%d %d", &R[i], &C[i]);
        

        for(j = 0; j < R[i]; ++j)
        {
            scanf("%s", g[i][j]);
        }

        scanf("%d %d", &r[i], &c[i]);
        
        for(j = 0; j < r[i]; ++j)
        {
            scanf("%s", p[i][j]);
        }
    }
    
    for(q = 0; q < t; ++q)
    {
        flag = 0;
        a = 0;
        b = 0;
        start = 0;
        I = 0;
        J = 0;
        count = 0;

        max_col = C[q] - c[q];
        max_row = R[q] - r[q];
        count_row = 0;
        //printf("R: %d, C: %d, r: %d, c: %d\n",R,C,r,c);
        for(i = 0;i <= max_row; ++i)
        {
            //printf("i: %d\n",i);
            for(j = 0; j <= max_col; ++j)
            {
                //printf("j: %d\n",j);
                I = i;
                J = j;
                flag = 0;
                if(g[q][i][j] != p[q][a][b])
                    continue;
                k = i;
                l = r[q];
                while(l)
                {
                    count = 0;

                    start = j;
                    while(j < C[q] && (g[q][k][j++] == p[q][a][b++]))
                    {
                        count++;
                        //printf("%d %d %d %d %d %d %d\n", g[k][j-1], p[a][b-1], count, k,j-1,a,b-1);
                    }
                    if(count == c[q])
                    {
                        --l;
                        j = start;
                        ++k;
                        b = 0;
                        ++a;
                        ++count_row;
                        //printf("%d %d %d \n", count_row, k,j);
                    }
                    else
                    {
                        //printf("else : %d %d \n", i,j);
                        a = 0;
                        b = 0;
                        j = J;
                        i = I;
                        count_row = 0;
                        break;
                    }
                    if(count_row == r[q])
                    {
                        flag = 1;
                        break;
                    }

                }
                if(flag == 1)
                    break;
            }
            if(flag == 1)
                break;
        }

        if(flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

}
