#include "implementation.h"

int main()
{
    FILE *f;
    studentlist l;
    student s;
    char line[100];
    int line_count = 0;

    f = fopen("Student_data.txt","r");

    while(!feof(f))
    {
        fscanf(f,"%s",line);
        assign(&s,line);

        l.list[line_count] = s;

        line_count++ ;
    }
    l.n = line_count;

    insert(&l,s,1);
    display(l);
    
    return 0;
}