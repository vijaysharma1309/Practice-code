#include<stdio.h>

/*
t = a
a = b
b = t
*/

void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp; 
}

void swap(void *a, int size_a, void *b, int size_b)
{
    int i;
    char *local_a = (char *)a; 
    char *local_b = (char *)b; 
    if(size_a == size_b)
    {
        for(i = 0; i < size_a; ++i)
        {
            swap_char(&local_a[i], &local_b[i]);
        }
    }
}

int main()
{
    int i;
    int int_a = 20;
    int int_b = 50;
    float float_a = 102.4;
    float float_b = 553.8;
    char char_a = 'a';
    char char_b = 'b';
    int int_arra[5] = {1,2,3,4,5};
    int int_arrb[5] = {6,7,8,9,0};
    char *str_a = "hello";
    char *str_b = "olleh";

    printf("before swap\n");
    printf("a: %s, b: %s\n", str_a, str_b);
    
    swap((void *)&str_a, sizeof(str_a), (void *)&str_b, sizeof(str_b));

    printf("before swap\n");
    printf("a: %s, b: %s\n", str_a, str_b);
    
    printf("before swap\n");
    for(i = 0; i < 5; ++i)
        printf("a: %d, b: %d\n", int_arra[i], int_arrb[i]);

    swap((void *)&int_arra, sizeof(int_arra), (void *)&int_arrb, sizeof(int_arrb));

    printf("after swap\n");
    for(i = 0; i < 5; ++i)
        printf("a: %d, b: %d\n", int_arra[i], int_arrb[i]);

    printf("before swap\n");
    printf("a: %c, b: %c\n", char_a, char_b);

    swap((void *)&char_a, sizeof(char_a), (void *)&char_b, sizeof(char_b));

    printf("after swap\n");
    printf("a: %c, b: %c\n", char_a, char_b);

    printf("before swap\n");
    printf("a: %d, b: %d\n", int_a, int_b);

    swap((void *)&int_a, sizeof(int_a), (void *)&int_b, sizeof(int_b));

    printf("after swap\n");
    printf("a: %d, b: %d\n", int_a, int_b);

    printf("before swap\n");
    printf("a: %lf, b: %lf\n", float_a, float_b);

    swap((void *)&float_a, sizeof(float_a), (void *)&float_b, sizeof(float_b));

    printf("after swap\n");
    printf("a: %lf, b: %lf\n", float_a, float_b);

}