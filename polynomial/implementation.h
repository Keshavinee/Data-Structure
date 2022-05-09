#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

term *init(term *head)
{
	// Initializing head with null
	head = NULL;
	return head;
}

term *insertEnd(term *head, int coefficient, int exponent)
{
	term *newNode, *temp;

	// Assigning value to a new node
	newNode = (term *)malloc(sizeof(term));
	newNode->coeff = coefficient;
	newNode->exp = exponent;
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

void display(term *head)
{
	term *temp;

	if (head != NULL)
	{
		temp = head;

		// Traversing through the linked list
		while (temp->next != NULL)
		{
			printf("%d x^%d + ", temp->coeff, temp->exp);
			temp = temp->next;
		}
		printf("%d x^%d\n", temp->coeff, temp->exp);
	}

	else
	{
		printf("It's a zero polynomial!\n");
	}
}

term *polyMul(term *h1, term *h2)
{
	term *h3, *t1, *t2;
	h3 = init(h3);

	t1 = h1;

	// Multiplying a term in one polynomial with another polynomial
	while (t1 != NULL)
	{
		t2 = h2;

		while (t2 != NULL)
		{
			h3 = insertEnd(h3, (t1->coeff * t2->coeff), (t1->exp + t2->exp));
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	return h3;
}

term * simplify(term *head){
	term *t1, *t2, *prev;
	
	t1 = head;
	
	while (t1 != NULL)
	{
		prev = t1;
		t2 = t1->next;

		while (t2 != NULL)
		{
			if (t1->exp == t2->exp)
			{
				// Combining like terms
				t1->coeff = t1->coeff + t2->coeff;
				prev->next = t2->next;
				t2 = prev->next;
			}
			else
			{
				prev = t2;
				t2 = t2->next;
			}
		}
		t1 = t1->next;
	}
	return head;
}

int degree(term *head){
	// degreee of a polynomial
	term *temp;
	int max;

	temp = head;

	while (temp != NULL)
	{
		if (temp->exp > max)
		{
			max = temp->exp;
		}
		temp = temp->next;
	}
	// If zero polynomial, the degree is randomly assigned
	return max;
}

int eval(term *head, int x){
	// Evaluates polynomial with the given value
	term *temp;
	int val = 0;

	temp = head;

	while (temp != NULL)
	{
		val = val + (temp->coeff)*(pow(x, temp->exp));
		temp = temp->next;
	}
	return val;

}
term *polyAdd(term *h1, term *h2)
{
	term *h3,*t1,*t2;
	h3 = NULL;

	if (t1 != NULL && t2!=NULL){
		if (h1->exp > h2->exp)
		{
			t1 = h1;
			t2 = h2;
		}
		else
		{
			t1 = h2;
			t2 = h1;
		}
	} // write for other two conitions
	while (t1 != NULL)
	{
		if (t2!=NULL && t1->exp == t2->exp)
		{
			h3 = insertEnd(h3, t1->coeff+t2->coeff, t1->exp);
			t2 = t2->next;
		}

		else
		{
			h3 = insertEnd(h3, t1->coeff, t1->exp);

			while (t2!= NULL && t1->next->exp < t2->exp)
			{
				h3 = insertEnd(h3,t2->coeff, t2->exp);
				t2 = t2->next;
			}
			
		}
		
		t1 = t1->next;		
	}
	
	return h3;
}
