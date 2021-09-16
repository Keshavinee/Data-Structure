#include "student.h"
#include<stdio.h>

void insert(studentlist *l, student s, int index)
{
    for (int i = l->n ; i > index; i--)
    {
        l->list[i] = l->list[i-1] ;
    }
    
    l->list[index] = s;
    l->n++;
}

void display_student_details(student s)
{
    printf("RegNo.: %d  ",s.regno);
    printf("Name : %s   ",s.name);
    printf("Mark 1 : %d ",s.mark[0]);
    printf("Mark 2 : %d ",s.mark[1]);
    printf("Mark 3 : %d ",s.mark[2]);
    printf("Total : %d  ",s.total);
    printf("Result : %c ",s.result);
}

void display(studentlist l)
{
    for (int i = 0; i < l.n; i++)
    {
        display_student_details(l.list[i]);
        printf("\n");
    }
    
}

void assign(student *s, char line[])
{
    char regno[20],m1[2],m2[2],m3[2],total[3];
    int i;
    for (i = 0; line[i] != " "; i++)
    {
        regno[i] = line[i];
    }
    s->regno = (int) regno;
    
    for (int j=0; line[i] != " "; j++)
    {
        s->name[j] = line[i];
        i++;
    }
    m1[0] = line[i] ; m1[1] = line[i+1];
    m2[0] = line[i+3] ; m2[1] = line[i+4];
    m3[0] = line[i+6] ; m3[1] = line[i+7];

    total[0] = line[i+9] ; total[1] = line[i+10] ; total[2] = line[i+11] ; 

    s->mark[0] = (int) m1 ; s->mark[1] = (int) m2 ; s->mark[2] = (int) m3 ; 
    s->total = (int) total;
    s->result = line[i+13];
}