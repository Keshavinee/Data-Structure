#include "doublyLinked.h"
#include <stdio.h>
#include <stdlib.h>

node *init(node *head)
{
    head = NULL;
    return head;
}

node *insertFront(node *head, char c)
{
    node *nw, *temp;

    // Creating new node
    nw = (node *)malloc(sizeof(node));
    nw->c = c;
    nw->next = NULL;
    nw->prev = NULL;

    if (head == NULL)
    {
        head = nw;
    }

    else
    {
        temp = head;
        head = nw;
        nw->next = temp;
        temp->prev = nw;
    }
    return head;
}

node *insertEnd(node *head, char c)
{
    node *nw, *temp;

    nw = (node *)malloc(sizeof(node));
    nw->c = c;
    nw->next = NULL;
    nw->prev = NULL;

    if (head == NULL)
    {
        head = nw;
    }

    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nw;
        nw->prev = temp;
    }
    return head;
}

node *insertMiddle(node *head, char d, char c)
{
    node *nw, *temp;

    nw = (node *)malloc(sizeof(node));
    nw->c = c;
    nw->next = NULL;
    nw->prev = NULL;

    temp = head;
    while (temp != NULL)
    {
        if (temp->c == d)
        {
            printf("%c is inserted.\n", c);

            nw->next = temp->next;
            temp->next = nw;
            nw->prev = temp;

            if (nw->next != NULL)
            {
                nw->next->prev = nw;
            }
            return head;
        }
        temp = temp->next;
    }
    printf("%c is not found!\n", d);
    return head;
}

void display(node *head)
{
    node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
    }

    else
    {
        temp = head;

        while (temp != NULL)
        {
            printf("%c ", temp->c);
            temp = temp->next;
        }
        //printf("%c\n", temp->c);

    }
}

node *deleteItem(node *head, char c)
{
    node *temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->c == c)
        {
            printf("%c is deleted!\n", c);
            if (temp->prev == NULL)
            {
                head = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = NULL;
                    temp->next = NULL;
                }
                return head;
            }

            if (temp->next != NULL)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->next = NULL;
            }
            else
            {
                temp->prev->next = NULL;
            }
            temp->prev = NULL;
            return head;
        }
        temp = temp->next;
    }
    printf("Character not found!\n");
    return head;
}

int searchItem(node *head, char c)
{
    node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        if (temp->c == c)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int palindrome(node *head)
{
    node *temp, *tail;
    temp = head;
    tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    while (!((temp->next == tail) | (temp == tail)))
    {
        if (temp->c != tail->c)
        {
            return 0;
        }
        tail = tail->prev;
        temp = temp->next;
    }
    if (temp->c == tail->c)
    {
        return 1;
    }
}

ptr separateList(node *head)
{
    ptr p;
    node *h1, *h2, *temp;
    h1 = init(h1);
    h2 = init(h2);
    temp = head;

    while (temp != NULL)
    {
        if ((temp->c == 'A') | (temp->c == 'E') | (temp->c == 'I') | (temp->c == 'O') | (temp->c == 'U'))
        {
            h1 = insertEnd(h1, temp->c);
        }
        else
        {
            h2 = insertEnd(h2, temp->c);
        }
        temp = temp->next;
    }
    p.h1 = h1;
    p.h2 = h2;
    return p;
}
node *swap(node *head, int k)
{
    node *temp, *tail;
    int n; char c;
    temp = head;
    tail = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
    }

    else
    {
        n = 1;
        while (tail->next != NULL)
        {
            tail = tail->next;
            n++;
        }

        if (k <= n)
        {
            while (k > 1)
            {
                temp = temp->next;
                tail = tail->prev;
                k--;
            }
            c = temp->c;
            temp->c = tail->c;
            tail->c = c;
        }
        else
        {
            printf("Node count exceeded!\n");
        }
    }
    return head;
}