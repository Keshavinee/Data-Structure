struct term 
{
	int coeff;
	int exp;
	struct term *next;
};

typedef struct term term;

term *init(term *);
term *insertEnd(term *, int , int );
void display(term *);
term *polyMul(term *, term *);
term * simplify(term *);
int degree(term *);
int eval(term *, int );
term *polyAdd(term *, term *);