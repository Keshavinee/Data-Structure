#include "eimpl.h"

int eval(node *t){
    if (t!=NULL)
    {
        if (t->data == '+')
        {
            return eval(t->right) + eval(t->left);
        }
        
        else if (t->data == '-')
        {
            return eval(t->right) - eval(t->left);
        }

        else if (t->data == '*')
        {
            return eval(t->right) * eval(t->left);
        }

        else if (t->data == '/')
        {
            return eval(t->right) / eval(t->left);
        }
        return (int) t->data % 48;
    }
    
}


int main(){
    char expr[20];
    stack *stk;
    node *tree;

    stk = (stack *)malloc(sizeof(stack));
    printf("Enter postfix expression: ");
    scanf("%s",expr);

    construct(stk,expr);

    tree = stk->list[stk->top];
    inorder(tree);
    
    printf("\nEvaluation of expression: %d\n",eval(tree));
    return 0;
}