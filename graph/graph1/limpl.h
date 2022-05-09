#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

node *initialize(node *head)
{
	// Initializing head with null
	head = NULL;
	return head;
}

node *insertEnd(node *head, int data)
{
	node *newNode, *temp;

	// Assigning value to a new node
	newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}

	else
	{
		temp = head;

		// Moving to the end of the list
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	return head;
}

void ldisplay(node *head)
{
	node *temp = head;

	while (temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

node *deleteItem(node *head, int data)
{
	node *temp, *prev;
	temp = head;
	prev = temp;

	if (temp != NULL && temp->data == data)
	{
		head = temp->next;
		return head;
	}
	
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			prev->next = temp->next;
			return head;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}

int searchItem(node *head, int data)
{
    node *temp = head;
    
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}