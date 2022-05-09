#include "list.h"
#include <stdio.h>
#include <stdlib.h>

node *init(node *head)
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

void display(node *head)
{
	node *temp;

	if (head != NULL)
	{
		temp = head;

		// Traversing through the linked list
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}


