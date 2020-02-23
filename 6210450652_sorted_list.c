//6210450652 Patchapon Rochananan
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
void sort(struct node *x,struct node *y)
{
    int tmp = x->data;
    x->data = y->data;
    y->data = tmp;
}
void sorting(struct node *first)
{
    int count = 1;
    struct node *current,*prev = NULL;
    while(count)
    {
        count = 0;
        current = first;
        while (current->next != prev)
        {
            if (current->data > current->next->data)
            {
                sort(current,current->next);
                count = 1;
            }
            current = current->next; 
        }
        prev = current;
    }
}
int main()
{
    int input;
    struct node *head = NULL,*second = NULL,*tmp;
    while(scanf("%d",&input) == 1)
    {
        
        if (input == -1)
        {
            break;
        }
        else if (input >= 0)
        {
        if (head == NULL)
        {
            head = second = (struct node *)malloc(sizeof(struct node));
        }
        else
        {
            second->next = (struct node *)malloc(sizeof(struct node));
            second = second->next;
        }
        second->data = input;
        second->next = NULL;
        sorting(head);
        }
    }
    for(tmp=head;tmp;tmp = tmp->next)
    {
        printf("%d\n",tmp->data);
    }
}