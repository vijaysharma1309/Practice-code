#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char str[24];
    int count;
    struct node *next;
};

void insert_list(char *str, struct node **head)
{
    struct node *temp = *head;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->str, str);
    new_node->count = 1;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;

        return;
    }
    temp->next = new_node;
    
    return;
}

void search_str(char *str, struct node **head)
{
    struct node *temp = *head;
    struct node *t2 = *head;
    int flag = 0;
    while(temp != NULL)
    {
        t2 = temp;
        if(!strcmp(str, temp->str))
        {
            flag = 1;
            ++temp->count;
            break;
        }
        temp = temp->next;
    }

    if(flag == 1)
    {
        return ;
    }
    
    insert_list(str, &t2);
    return ;
}

void build_list(char **str, int n, struct node **head)
{
    int i;
    
    insert_list(str[0], head);

    for(i = 1; i < n; ++i)
    {
        search_str(str[i], head);
    }
}

int search_query(char *query, struct node **head)
{
    struct node *temp = *head;

    while(temp != NULL)
    {
        if(!strcmp(query, temp->str))
        {
            return temp->count;
        }
        temp = temp->next;
    }

    return 0;
}

void free_list(struct node **head)
{
    struct node *temp = *head;

    while(temp != NULL)
    {
        temp = *head;
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}

int main()
{
    int n, q, i;

    struct node *head = NULL;
   
    scanf("%d", &n);

    char **str = (char **)malloc(n * sizeof(char *));
    for(i = 0; i < n; ++i)
    {
        str[i] = (char *)malloc(24 * sizeof(char));
        scanf("%s", str[i]);
    }
    
    scanf("%d", &q);
    char **query = (char **)malloc(q * sizeof(char *));
    for(i = 0; i < q; ++i)
    {
        query[i] = (char *)malloc(24 * sizeof(char));
        scanf("%s", query[i]);
    }

    build_list(str, n, &head);  
    
    for(i = 0; i < q; ++i)
    {
        printf("%d\n", search_query(query[i], &head));
    }
    
    free_list(&head);

    free(str);
    free(query);
}
