struct node 
{
	int data;
	struct node *next;
};

typedef struct node node;

node *init(node *);
node *insertEnd(node *, int);
void display(node *);