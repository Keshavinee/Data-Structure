#include "list.h"
#include <stdio.h>
#include <stdlib.h>

node *init(node *head)
{
    head = NULL;
    return head;
}

node *insertEnd(node *head, int d)
{
    node *newNode, *temp;

    newNode = (node *)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = head;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

node *insertFront(node *head, int d)
{
    node *newNode, *temp;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = d;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
    return head;
}

void display(node *head)
{
    node *temp;
    if (head != NULL)
    {
        temp = head;
        while (temp->next != head)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
        printf("%d\n", temp->next->next->data);
    }
}