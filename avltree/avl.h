#include "list_impl.h"

struct avltree
{
	int element;
	struct avltree *left;
    struct avltree *right;
	int height;
};


struct avltree *insert(struct avltree *, int );
void inorder(struct avltree *);
node ** levelorder(struct avltree *);