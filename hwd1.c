
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list
{
    char word[20];
    struct list *next;
} list;

list * insert_sorted(list *head, char *word)
{
    list *new_node = (list *)malloc(sizeof(list));
    if(new_node == NULL)
    {
        printf("ERROR Memory Allocation!\n");
        exit(1);
    }
    strcpy(new_node->word, word);
    if(head == NULL || strcmp(word, head->word) < 0)
    {
        new_node->next = head;
        return new_node;
    }
    list *current = head;
    while(current->next !=NULL && strcmp(word, current->next->word)>=0)
    {
        current=current->next;
    }
    new_node->next=current->next;
    current->next=new_node;
    return head;
}

void print_list( list *head)
{
    while (head != NULL)
    {
        printf("%s", head->word);
        head = head->next;
        if (head != NULL)
        {
            printf(" ");
        }
    }
}

void delete_list( list **head)
{
    list *current = *head;
    while (current != NULL)
    {
        list *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}


int main()
{
    char str[1000];
    struct list *head = NULL;
    fgets(str, 1000, stdin);
    str[strcspn(str, ".")] = '\0';
    char *word = strtok(str, " ");
    while(word != NULL)
    {
        head = insert_sorted(head, word);
        word=strtok(NULL, " ");
    }
    print_list(head);
    delete_list(&head);
    return 0;
}

