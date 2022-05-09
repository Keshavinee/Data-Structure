#include "list_impl.h"

struct BST{
	int data;
	struct BST *left, *right;
};

struct BST * insert(struct BST *, int);
int * inorder(struct BST *);
struct BST * findmin(struct BST *);
struct BST * find(struct BST *, int);
struct BST * delete(struct BST *, int );
node ** levelorder(struct BST *);
int height(struct BST *);