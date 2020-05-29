#include<stdio.h>
#include<stdlib.h>

unsigned int max;
unsigned int arr[100000];
int top = -1;

unsigned int find_max()
{
    int i;
    unsigned l_max = arr[0];

    if(top == -1)
    {
        return 0;
    }

    for(i = 1; i <= top; ++i)
    {
        if(l_max < arr[i])
        {
            l_max = arr[i];
        }
    }
    
    return l_max;
}

void stack_push(unsigned int value)
{
    ++top;
    arr[top] = value;
}

void stack_pop()
{
    if(top == -1)
    {
        return;
    }

    --top;
    max = find_max(top);
}

int main()
{
    unsigned int i, n, op, value;
    
    scanf("%d", &n);

    for(i = 0; i < n; ++i)
    {
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            {
                scanf("%d", &value);
                if(max < value)
                {
                    max = value;
                }

                stack_push(value);
            }
            break;

            case 2:
            {
                stack_pop();
            }
            break;

            case 3:
            {
                printf("%d\n", max);
            }
            break;

            default:
                printf("Invalid operation\n");
        }
    }
}
