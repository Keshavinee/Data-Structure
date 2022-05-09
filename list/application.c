#include "implementation.h"

int main(){
    studentlist l,r;
    student s;
    int c,regno;
    char *name;

    init(&l);

    printf("List Operations:\nMenu\n1.Insert at front\n\
2.Insert at end\n3.Insert after regno\n4.Display\n5.\
Delete an item\n6.Search a name\n7.Passed students\n\
8.Students securd first class\n9.Update result\n10.Create list\
\n11.Quit\n");

    option :
        printf("Enter any of the options above: ");
        scanf("%d",&c);

    switch (c)
    {
    case 1:
        create(&s);
        insertFront(&l,s);

        printf("Student details is inserted at front!\n");
        goto option;

    case 2:
        create(&s);
        insertEnd(&l,s);

        printf("Student details is inserted at end!\n");
        goto option;

    case 3:
        create(&s);
        printf("Enter regno:");
        scanf("%d",&regno);

        insertRegNo(&l,s,regno);

        printf("Student details is inserted after given\
register number!\n");
        goto option;

    case 4:
        for (int i = 0; i < l.n; i++)
        {
            display(l.list[i]);
        }
        
        goto option;

    case 5:
        printf("Enter regno:");
        scanf("%d",&regno);

        deleteStudent(&l,regno);

        printf("Student details are deleted for given\
register number!\n");
        goto option;

    case 6:
        printf("Enter name:");
        scanf("%s",name);

        searchName(l,name);
        goto option;

    case 7:
        r = result(l);
        for (int i = 0; i < r.n; i++)
        {
            display(r.list[i]);
        }
        
        goto option;

    case 8:
        printf("No.of students secured first class: %d",firstClass(l));
        goto option;
    
    case 9:
        computeResult(&l);
        goto option;

    case 10:
        for (int i = 0; i < l.n; i++)
        {
            printf("Student %d:\n",i+1);
            create(&s);
            l.list[i] = s;
        }
        
        goto option;
        
    case 11:
        printf("Program ended!\n");
        break;

    default:
        printf("Invalid Option!\n");
        goto option;
    }
    return 0;
}