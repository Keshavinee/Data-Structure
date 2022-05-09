#include "impl.h"

int main(){
    node *h;
    int c, k;
    char data, d;
    ptr p;

    h = init(h);

    printf("List Operations:\nMenu\n1.Insert at front\n\
2.Insert at end\n3.Insert at middle\n4.Display\n5.\
Delete an item\n6.Search an item\n7.Palindrome\n\
8.Separate vowels & consonants\n9.Swap Kth nodes\n10.Quit\n");

    option :
        printf("Enter any of the options above: ");
        scanf("%d",&c);

    switch (c)
    {
    case 1:
        printf("Enter a character:");
        scanf(" %c",&data);

        h = insertFront(h, data);
        printf("%c is inserted!\n",data);
        goto option;

    case 2:
        printf("Enter a character:");
        scanf(" %c",&data);

        h = insertEnd(h, data);
        printf("%c is inserted!\n",data);
        goto option;

    case 3:
        printf("Enter character to be inserted and another character to point out location :");
        scanf(" %c %c",&data, &d);

        h = insertMiddle(h, data, d);
        goto option;

    case 4:
        display(h);
        goto option;

    case 5:
        printf("Enter an item to delete:");
        scanf(" %c",&data);

        h = deleteItem(h, data);
        goto option;

    case 6:
        printf("Enter an item to search: ");
        scanf(" %c",&data);

        printf("Occurences of %c is %d.\n",data,searchItem(h, data));
        goto option;

    case 7:

        if (palindrome(h) == 1)
        {
            printf("Characters in the list forms a palindrome!\n");
        }
        else
        {
            printf("Characters in the list doesn't form a palindrome!\n");
        }
        
        goto option;

    case 8:
        p = separateList(h);
        display(p.h1); display(p.h2);
        goto option;
    
    case 9:
        printf("Enter kth node:");
        scanf("%d",&k);

        h = swap(h,k);
        display(h);

        goto option;
        
    case 10:
        printf("Program ended!\n");
        break;

    default:
        printf("Invalid Option!\n");
        goto option;
    }
    return 0;
}