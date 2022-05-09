#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 50

struct BST *insert(struct BST *t, int x)
{
	if (t == NULL)
	{
		struct BST *node = (struct BST *)malloc(sizeof(struct BST));
		node->data = x;
		node->left = NULL;
		node->right = NULL;
		t = node;
	}
	else
	{
		if (x < t->data)
		{
			t->left = insert(t->left, x);
		}
		else if (x > t->data)
		{
			t->right = insert(t->right, x);
		}
	}
	return t;
}

int *inorder(struct BST *t)
{
	static int arr[size], k = 0;
	if (t != NULL)
	{
		inorder(t->left);
		arr[k] = t->data;
		k++;
		printf("%d ", t->data);
		inorder(t->right);
	}
	return &arr[0];
}

/*int *inorder(struct BST *t){
	int h = height(t);
	int size = (int) pow(2,h+1)-1;
	int arr[size];
	return inorderR(t,0,arr);
}*/


struct BST *findmin(struct BST *t)
{
	if (t != NULL)
	{
		if (t->left != NULL)
		{
			return findmin(t->left);
		}

		else
		{
			return t;
		}
	}
	return t;
}

struct BST *find(struct BST *t, int x)
{
	if (t != NULL)
	{
		if (t->data == x)
		{
			return t;
		}

		else if (t->data < x)
		{
			return find(t->right, x);
		}

		else
		{
			return find(t->left, x);
		}
	}
}

struct BST *min(struct BST *t)
{
	if (t->left->left != NULL)
	{
		return min(t->left);
	}

	return t;
}

struct BST *delete (struct BST *t, int x)
{
	if (t != NULL)
	{
		if (t->data == x)
		{
			if (t->left == NULL && t->right == NULL)
			{
				t = NULL;
			}

			else if (t->left == NULL)
			{
				t = t->right;
			}

			else if (t->right == NULL)
			{
				t = t->left;
			}

			else
			{
				struct BST *p;
				struct BST *st = t->right;
				if (st->left == NULL)
				{
					st->left = t->left;
					t = st;
				}
				else
				{
					st = min(st);
					p = st->left;
					st->left = NULL;
					p->left = t->left;
					p->right = t->right;
					t = p;
				}
				
			}
		}

		else if (t->data < x)
		{
			t->right = delete (t->right, x);
		}

		else
		{
			t->left = delete (t->left, x);
		}
	}

	return t;
}

node ** levelorder(struct BST *t)
{
	static node *arr[size];
	static int i = 0;

	if (t != NULL)
	{
		arr[i] = insertEnd(arr[i], t->data);
		i++;

		levelorder(t->left);
		levelorder(t->right);
		i--;
	}
	return &arr[0];
}

/*node ** levelorder(struct BST *t){
	int h = height(t);
	node *arr[h];
	for (int k = 0; k < h; k++) arr[k] = NULL;
	
	return levelorderR(t,0,arr);
}*/

int height(struct BST *t){
	static int j = 0, max = 0;
	
	if (t != NULL)
	{
		j++;
		height(t->left);
		if (j > max)
		{
			max = j;
		}
		
		height(t->right);
		j--;
	}
	return max;
}

/*int height(struct BST *t){
	return heightR(t,0,0);
}*/
