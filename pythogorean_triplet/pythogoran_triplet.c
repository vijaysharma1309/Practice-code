#include<stdio.h>
#include<stdlib.h>

int triplets(int *arr, int n)
{
    int i, j, k;
    
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            //if(arr[i] != arr[j])
            {
                for(k = 0; k < n; ++k)
                {
                    //if(arr[i]!= arr[k] && arr[j] != arr[k])
                    {
                        int max = (arr[i] > arr[j]) ? ((arr[i] > arr[k]) ? arr[i] : arr[k]) : ((arr[j] > arr[k]) ? arr[j] : arr[k]);

                        if(max == arr[i])
                        {
                            if((max*max) == (arr[j]*arr[j] + arr[k]*arr[k]))
                            {
                                return 1;
                            }
                        }
                        else if(max == arr[j])
                        {
                            if((max*max) == (arr[i]*arr[i] + arr[k]*arr[k]))
                            {
                                return 1;
                            }
                        }
                        else if(max == arr[k])
                        {
                            if((max*max) == (arr[j]*arr[j] + arr[i]*arr[i]))
                            {
                                return 1;
                            }
                        }


                        /*if((a == b+c) || (b == a+c) || (c == a+b))
                        {
                            return 1;
                        }*/
                    }
                }
            }
        }
    }
    
    return 0;
}

int main()
{
    int t, i, j, k;
    int n;
    int *arr = NULL;
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d", &n);
        arr = (int *)malloc(n * sizeof(int));
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        
        if(triplets(arr, n))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        
        free(arr);
    }
}
