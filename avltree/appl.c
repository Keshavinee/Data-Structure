#include "impl.h"

int main(){
    struct avltree *t = NULL;
    node **a;

    t=insert(t,23); 
    t=insert(t,12);
    t=insert(t,13);
    t=insert(t,4);
    t=insert(t,45);
    t=insert(t,54);

	a = levelorder(t);
	for (int i = 0; i <= height(t); i++)
	{
		printf("Level %d : ",i+1);
		display(*a);
		printf("\n");
		a++;
	}

    inorder(t);

    return 0;
}