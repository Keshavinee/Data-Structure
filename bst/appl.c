#include "impl.h"

int completeTree(struct BST *);
int equal(struct BST *, struct BST *);


int main(){
	struct BST *t1, *t2; 
	node **a;
	int h;
	t1 = NULL;
	t1 = insert(t1,29);
	t1 = insert(t1,23);
	t1= insert(t1,4);
	t1= insert(t1,13);
	t1= insert(t1,39);
	t1= insert(t1,31);
	t1= insert(t1,30);
	t1= insert(t1,45);
	t1= insert(t1,56);
	t1= insert(t1,49);
	t1= insert(t1,42);
	t1= insert(t1,14);
	t1= insert(t1,12);
	t1= insert(t1,11);

	h = height(t1);
	printf("%d\n",h);
	a = levelorder(t1);
	for (int i = 0; i < h; i++)
	{
		printf("Level %d : ",i+1);
		display(*a);
		printf("\n");
		a++;
	}
	
	/*t1 = delete(t1,39);
	inorder (t1);
	printf("\n");
	t1 = delete(t1,30);
	inorder (t1);
	printf("\n");
	/*t2 = NULL;
	t2 = insert(t2,29);
	t2 = insert(t2,25);
	t2= insert(t2,4);
	t2= insert(t2,15);
	t2= insert(t2,40);
	t2= insert(t2,31);
	t2= insert(t2,45);
	t2= insert(t2,56);
	t2= insert(t2,49);

	//printf("%d %p\n",findmin(t)->data, findmin(t));
	//t = delete(t,13);
	//a = inorder(t);

	/*printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ",*a);
		a++;
	}
	printf("%p %p\n",t1,t2);
	equal(t1,t2);*/


	return 0;
}

int equal(struct BST *t1, struct BST *t2){
	int *a1, *a2, n1, n2;
	a1 = inorder(t1);
	a2 = inorder(t2);

	n1 = sizeof(a1) / sizeof(int);
	n2 = sizeof(a2) / sizeof(int);

	printf("%p %p\n",a1,a2);
	for (int i = 0; i < n1 ; i++)
	{
		printf("%d %d\n",*a1,*a2);
		a1++;
		a2++;
	}

	for (int i = 0; i < n2; i++)
	{
		if (*a1 != *a2)
		{
			printf("Unidentical\n");
			return 0;
		}
	}
	printf("Identical\n");
	return 1;

}


