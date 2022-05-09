#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

#define size 20

static int height (struct avltree *t)
{
	if(t==NULL)
		return -1;
	else
		return t->height;
}

int max(int h1, int h2){
	if (h1 > h2)
	{
		return h1;
	}
	return h2;
}

struct avltree* singlerotatewithleft(struct avltree *k2)
{
	struct avltree *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;

	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct avltree* singlerotatewithright(struct avltree *k2)
{
	struct avltree *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;

	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct avltree* doublerotatewithleft(struct avltree *k3)
{ 
    //rotate between k1 and k2
	k3->left=singlerotatewithright(k3->left);

	//rotate between k3 and k2
	return singlerotatewithleft(k3);
}

struct avltree* doublerotatewithright(struct avltree *k3)
{ 
    //rotate between k1 and k2
	k3->left=singlerotatewithleft(k3->left);

	//rotate between k3 and k2
	return singlerotatewithright(k3);
}


struct avltree* insert (struct avltree *t, int x)
{
	if(t==NULL)
	{
		t= (struct avltree*) malloc(sizeof(struct avltree));
		t->element=x;		
		t->height=0;
		t->left=NULL;
		t->right=NULL;	
	}

	else if(x<t->element)
	{
		t->left=insert(t->left,x);
		if(height(t->left)-height(t->right) ==2 | height(t->left)-height(t->right) ==-2)
			if(x<t->left->element)
				t=singlerotatewithleft(t);
			else
				t=doublerotatewithleft(t);
	}

	else if(x>t->element)
	{
		t->right=insert(t->right,x);
		if(height(t->left)-height(t->right) ==2 | height(t->left)-height(t->right) ==-2)
			if(x>t->right->element)
				t=singlerotatewithright(t);
			else
				t=doublerotatewithright(t);
	}

	t->height=max(height(t->left),height(t->right))+1;
	return t;
}


void inorder(struct avltree *t)
{
	if (t != NULL)
	{
		inorder(t->left);
		printf("%d ",t->element);
		inorder(t->right);
	}
}

node ** levelorder(struct avltree *t)
{
	static node *arr[size];
	static int i = 0;

	if (t != NULL)
	{
		arr[i] = insertEnd(arr[i], t->element);
		i++;

		levelorder(t->left);
		levelorder(t->right);
		i--;
	}
	return &arr[0];
}

