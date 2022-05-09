#include "implementation.h"

int main()
{
	term *h1, *h2, *h3;
    int c, n, coeff, exp;
    
    printf("Polynomial:\nMenu\n1.Creation\n2.Addition\n3.Multiplication\n");
    printf("4.Simplifying polynomial\n5.Degree of polynomial\n6.Evaluation of polynomial\n");
    printf("7.Quit\n");

    option :
        printf("Enter any of the options above: ");
        scanf("%d",&c);

    switch (c)
    {
    case 1:
        h1 = init(h1);
        h2 = init(h2);

        printf("Creation of first polynomial:\nNo.of terms:");
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
            printf("\nEnter coefficient and exponent: ");
		    scanf("%d %d",&coeff, &exp);
            h1 = insertEnd(h1, coeff, exp);
        }

        printf("Creation of second polynomial:\nNo.of terms:");
        scanf("%d",&n);

        for (int i = 0; i < n; i++)
        {
            printf("\nEnter coefficient and exponent: ");
		    scanf("%d %d",&coeff, &exp);
            h2 = insertEnd(h2, coeff, exp);
        }
        display(h1);
        display(h2);
		goto option;
			

    case 2:
		display(polyAdd(h1,h2));
        goto option;

	case 3:
        h3 = init(h3);
        h3 = polyMul(h1,h2);
		display(h3);
		goto option;
	
	case 4:
        h3 = simplify(h3);
		display(h3);
		goto option;

    case 5:
        printf("Input: "); display(h3);
        printf("Degree of polynomial: %d\n",degree(h3));
        goto option;

    case 6:
        display(h3);
        printf("\nEnter x: ");
        scanf("%d",&n);

        printf("Value is: %d\n",eval(h3, n));
        goto option;

    case 7:
        printf("Program ended!\n");
        break;

    default:
        printf("Invalid option!\n");
        break;
    }
	return 0;
}
