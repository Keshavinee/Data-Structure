struct node
{
    char c;
    struct node *prev, *next;
};

typedef struct node node;

struct ptr
{
    node *h1;
    node *h2;
};
typedef struct ptr ptr;

// operations
node *insertFront(node *, char);
node *insertEnd(node *, char);
node *insertMiddle(node *, char, char);
void display(node * );
node *deleteItem(node *, char );
node *init(node *);
int searchItem(node *, char );

// applications
int palindrome(node *);
ptr separateList(node *);
node *swap(node *, int );
