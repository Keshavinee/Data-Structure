#include "simpl.h"
#include "stdlib.h"


void construct(stack *stk, char *d){
    node *c;
    
    while (*d != '\0')
    {
        c = (node *)malloc(sizeof(node));
        c->data = *d;
        c->left = NULL; 
        c->right = NULL;

        if (*d>='0' && *d<='9')
        {
            push(stk, c);
        }

        else
        {
            c->right = pop(stk);
            c->left = pop(stk);
            push(stk, c);
        }
        d++;
    }
    
        
}

void inorder(node *tree){
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%c",tree->data);
        inorder(tree->right);
    }
}

void preorder(node *tree){
    if (tree != NULL)
    {
        printf("%c",tree->data);
        inorder(tree->left);
        inorder(tree->right);
    }
}

void postorder(node *tree){
    if (tree != NULL)
    {
        inorder(tree->left);
        inorder(tree->right);
        printf("%c",tree->data);
    }
}
