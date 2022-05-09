#include "student.h"
#include <stdio.h>
#include <stdlib.h>

// Initialising StudentList ADT 
void init(studentlist *l)
{
    int n;
    printf("Enter number of students:");
    scanf("%d", &n);
    l->n = n;
}

// Uploading information of a student 
void create(student *s)
{
    printf("RegNo.:");
    scanf("%d", &s->regno);
    printf("Name :");
    scanf(" %s", s->name);
    printf("Mark 1 :");
    scanf("%f", &s->mark[0]);
    printf("Mark 2 :");
    scanf("%f", &s->mark[1]);
    printf("Mark 3 :");
    scanf("%f", &s->mark[2]);
    printf("Total :");
    scanf("%f", &s->total);
    printf("Result :");
    scanf(" %c", &s->result);
}

// Inserting a student's data at the front of the list
void insertFront(studentlist *l, student s)
{
    if (size <= l->n)
    {
        printf("List overflow !");
    }

    else
    {
        for (int i = l->n; i > 0; i--)
        {
            l->list[i] = l->list[i - 1];
        }

        l->list[0] = s;
        l->n++;
    }
}

// Inserting a student's data at the end of the list
void insertEnd(studentlist *l, student s)
{
    if (size <= l->n)
    {
        printf("List overflow !");
    }

    else
    {
        l->list[l->n] = s;
        l->n++;
    }
}

// Inserting a student's data after a given Regno in the list 
void insertRegNo(studentlist *l, student s, int regNum)
{
    int i = 0;

    if (size <= l->n)
    {
        printf("List overflow !");
    }

    else
    {
        while (i < l->n)
        {
            if (l->list[i].regno == regNum)
            {
                break;
            }
            i++;
        }

        for (int j = l->n; j > i + 1; j--)
        {
            l->list[j] = l->list[j - 1];
        }

        l->list[i + 1] = s;
        l->n++;
    }
}

// Display student's data
void display(student s)
{
    printf("RegNo.: %d  ", s.regno);
    printf("Name : %s   ", s.name);
    printf("Mark 1 : %f ", s.mark[0]);
    printf("Mark 2 : %f ", s.mark[1]);
    printf("Mark 3 : %f ", s.mark[2]);
    printf("Total : %f ", s.total);
    printf("Result : %c \n", s.result);
}

// Displaying the details of students based on name of the student 
void searchName(studentlist l, char *name)
{
    for (int i = 0; i < l.n; i++)
    {
        if (l.list[i].name == name)
        {
            display(l.list[i]);
            break;
        }
    }
}

// Finfing the index of given data
int find(studentlist *l, int regNum)
{
    int i = 0;

    while (i < l->n)
    {
        if (l->list[i].regno == regNum)
        {
            return i;
        }
        i++;
    }

    return -1;
}

// Delete record given a register number  
void deleteStudent(studentlist *l, int regNum)
{
    int pos = find(l, regNum);

    if (pos == -1)
    {
        printf("Register number is not found!\n");
    }

    else
    {
        for (int i = pos; i < l->n - 1; i++)
        {
            l->list[i] = l->list[i + 1];
        }
        l->n--;
    }
}

// listing the students who have passed
studentlist result(studentlist l)
{
    int j = 0;
    studentlist r;

    for (int i = 0; i < l.n; i++)
    {
        if (l.list[i].result == 'P')
        {
            r.list[j] = l.list[i];
            j++;
        }
    }
    r.n = j;
    return r;
}

// Listing the students how many have secured First Class
int firstClass(studentlist l){
    int n;
    for (int i = 0; i < l.n; i++)
    {
        if (l.list[i].total >= 250.0)
        {
            n++;
        }
        
    }
    return n;
}

// Calculating the Total and updating the Result field about whether he / she is 
// passed or not
void computeResult(studentlist *l){
    for (int i = 0; i < l->n; i++)
    {
        if (l->list[i].total >= 150.0)
        {
            l->list[i].result = 'P';
        }
        else
        {
            l->list[i].result = 'F';
        }
        
    }
    
}