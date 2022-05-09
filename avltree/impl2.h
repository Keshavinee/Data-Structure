#include "dictionaryADT.h"
#include <stdio.h>
#include <stdlib.h>

#define size 20

static int height (struct dictionaryADT *t)
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

struct dictionaryADT* singlerotatewithleft(struct dictionaryADT *k2)
{
	struct dictionaryADT *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;

	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct dictionaryADT* singlerotatewithright(struct dictionaryADT *k2)
{
	struct dictionaryADT *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;

	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),height(k1->right))+1;

	return k1;
}

struct dictionaryADT* doublerotatewithleft(struct dictionaryADT *k3)
{ 
    //rotate between k1 and k2
	k3->left=singlerotatewithright(k3->left);

	//rotate between k3 and k2
	return singlerotatewithleft(k3);
}

struct dictionaryADT* doublerotatewithright(struct dictionaryADT *k3)
{ 
    //rotate between k1 and k2
	k3->right=singlerotatewithleft(k3->right);

	//rotate between k3 and k2
	return singlerotatewithright(k3);
}


struct dictionaryADT* insert (struct dictionaryADT *t, struct wordMeaning x)
{
	if(t==NULL)
	{
		t= (struct dictionaryADT*) malloc(sizeof(struct dictionaryADT));
		t->element=x;		
		t->height=0;
		t->left=NULL;
		t->right=NULL;	
	}

	else if(x.word<t->element.word)
	{
		t->left=insert(t->left,x);
		if(height(t->left)-height(t->right) ==2 | height(t->left)-height(t->right) ==-2)
			if(x.word<t->left->element.word)
				t=singlerotatewithleft(t);
			else
				t=doublerotatewithleft(t);
	}

	else if(x.word>t->element.word)
	{
		t->right=insert(t->right,x);
		if(height(t->left)-height(t->right) ==2 | height(t->left)-height(t->right) ==-2)
			if(x.word>t->right->element.word)
				t=singlerotatewithright(t);
			else
				t=doublerotatewithright(t);
	}

	t->height=max(height(t->left),height(t->right))+1;
	return t;
}


void inorder(struct dictionaryADT *t)
{
	if (t != NULL)
	{
		inorder(t->left);
		printf("%s - %s\n",t->element.word,t->element.meaning);
		inorder(t->right);
	}
}

void search(struct dictionaryADT *t, char word[]){
    if (t!=NULL)
    {
        if (t->element.word == word)
        {
            printf("%s\n",t->element.meaning);
        }
        else if (t->element.word < word)
        {
            search(t->right,word);
        }
        else if (t->element.word > word)
        {
            search(t->left,word);
        }    
    }
}

