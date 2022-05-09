struct node 
{
    int d;
    struct node *left, *right;    
};

typedef struct node node;

node *insert(node *, int);