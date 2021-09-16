#define size 20

struct student
{
    int regno;
    char *name;
    int mark[3];
    int total;
    char result;
};
typedef struct student student;

struct studentlist
{
    student list[size];
    int n;
};
typedef struct studentlist studentlist;
