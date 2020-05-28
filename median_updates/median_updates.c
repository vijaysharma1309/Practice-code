#include<stdio.h>
#include<stdlib.h>
#include <time.h> 

struct node{
    long long int data;
    struct node *next;
};

struct data_input_s{
    int num;
    char op;
};

struct node *middle = NULL;
int count, mid_count;

void insert_node(struct node **head, long long int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head;
    struct node *t2 = *head;
    int l_count = 0;

    ++count;
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    if(data > middle->data)
        temp = middle;

    while(temp != NULL)
    {
        if(temp->data < data)
        {
            t2 = temp;
            ++l_count;
            temp = temp->next;
        }
        else
            break;
    }
    
    if(temp == NULL)
    {
        t2->next = new_node;
    }
    else if(temp == *head)
    {
        new_node->next = temp;
        *head = new_node;
    }
    
    else
    {   
        new_node->next = t2->next;
        t2->next = new_node;
    }
    
    return;
}

void display(struct node **head)
{
   struct node *temp = *head;

   while(temp != NULL)
   {
       printf("%lld\n", temp->data);
       temp = temp->next;
   }

   return;
}

int search_pos(struct node **head, long long int data)
{
    struct node *temp = *head;
    int l_count = 0, flag = 0;
    
    if(*head == NULL)
    {
        return -1;
    }

    /*if(data > middle->data)
    {
        temp = middle;
        l_count = mid_count;
    }*/

    while(temp->data != data && temp->next != NULL)
    {
        ++l_count;
        temp = temp->next;
    }
    
    if(temp->data == data)
    {
        //printf("delete pos: %d, value: %lld\n", l_count, temp->data);
        flag = 1;
    }
    if(flag == 0)
        l_count = -1;

    return l_count;
}

int delete_pos(struct node **head, long long int data)
{
    struct node *temp = *head;
    struct node *t2 = *head;
    int l_count = 1;

    /*if(count == 0)
    {
        return -1;
    }*/
    --count;

    if(data > middle->data)
    {
        temp = middle;
        while(temp->data != data && temp != NULL)
        {
            t2 = temp;
            temp = temp->next;
        }
    }
    else
    {
        if(temp == *head && count == 0)
        {
            *head = NULL;
            free(temp);
            return -1;
        }
        while(temp->data != data && temp != middle->next)
        {
            t2 = temp;
            temp = temp->next;
        }
    }
    if(temp->data == data && temp != *head)
    {
        t2->next = temp->next;
        free(temp);
        return 0;
    }
    else if(temp == *head)
    {
        *head = temp->next;
        free(temp);
    }
    else
    {
        return -1;
    }

    return 0;
}

long double find_median(struct node **head)
{
    struct node *slow = *head;
    struct node *fast = *head;
    int l_count = 0;
    long double l_median = 0.0;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    middle = slow;
    mid_count = count/2;

    if(count % 2)
    {
        l_median = slow->data;
    }
    else
    {
        l_median = slow->data + slow->next->data;
    }
    
    return l_median;
}

int main()
{
    long double l_median = 0.0;
    int n, i, j, num, pos;
    char op;

    /*clock_t t; 
    t = clock();*/

    struct node *head = NULL;

    scanf("%d", &n);
    
    struct data_input_s *data_input = (struct data_input_s *)malloc(n * sizeof(struct data_input_s));
    for(i = 0; i < n; ++i)
    {
        scanf(" %c %d", &data_input[i].op, &data_input[i].num);
    /*}
    
    for(i = 0; i < n; ++i)
    { */  
        //printf("opt: %c, value: %d || output: %s\n", data_input[i].op, data_input[i].num, answer[i]);

        if(data_input[i].op == 'a')
        {
            insert_node(&head, data_input[i].num);
            l_median = find_median(&head);
            if(head == NULL)
            {
                printf("Wrong!\n");
                continue;
            }
            if(count % 2)
            {
                printf("%0.0Lf\n", l_median);
            }
            else
            {
                if((long int)(l_median/2 * 10) % 10)
                    printf("%0.1Lf\n", l_median/2);
                else
                    printf("%0.0Lf\n", l_median/2);
            }
        }
        else
        {   
            /*pos = search_pos(&head, data_input[i].num);
            if(pos == -1)
            {
                printf("Wrong!\n");
                continue;
            }*/
            
            if(head == NULL)
            {
                printf("Wrong!\n");
                continue;
            }
            if(delete_pos(&head, data_input[i].num))
            {
                printf("Wrong!\n");
                continue;
            }
            l_median = find_median(&head);
            if(count % 2)
            {
                printf("%0.0Lf\n", l_median);
            }
            else
            {
                if((long int)(l_median/2 * 10) % 10)
                    printf("%0.1Lf\n", l_median/2);
                else
                    printf("%0.0Lf\n", l_median/2);
            }
        }
        //printf("\n"); 
        //display(&head);
        //printf("\n");
        
    }
    
    free(data_input);
    /*t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("took %f seconds to execute \n", time_taken);*/

    /*in sec
    10000 = 0.67
    20000 = 3.2
    40000 = 15.42
    100000 = 175

    */
}
