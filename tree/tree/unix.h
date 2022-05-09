#ifndef UNIX_H
#define UNIX_H

struct node
{
    int data;
    struct node *children, *sibling;
};

typedef struct node node;

void display(node *t)

#endif