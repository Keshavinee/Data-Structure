#define size 20

// StudentADt with the certain fields
struct student
{
    int regno;
    char name[50] ;
    float mark[3];
    float total;
    char result;
};
typedef struct student student;

// StudentList ADT contains set of students' details
struct studentlist
{
    student list[size];
    int n;
};
typedef struct studentlist studentlist;

// Implementations for the following operations 
void init(studentlist *);
void create(student *);
void insertFront(studentlist *, student);
void insertEnd(studentlist *, student);
void insertRegNo(studentlist *, student, int);
void searchName(studentlist , char *);
int find(studentlist *, int );
void deleteStudent(studentlist *, int);
studentlist result(studentlist l);
int firstClass(studentlist );
void computeResult(studentlist *);
void display(student);