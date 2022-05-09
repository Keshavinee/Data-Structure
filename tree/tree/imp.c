#include "unix.h"
#include <stdio.h>

void display(node *t){
    node *temp;

    if (t!=NULL)
    {
        temp = t;
        printf("%d\n",temp->data);

        if (temp->children!=NULL)
        {
            printf("    ");
            display(temp->children);
        }

        if (temp->sibling!=NULL)
        {
            display(temp->children);
        }    
    }    
}