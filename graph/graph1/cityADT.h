struct cityADT
{
    int v;
    int e;
    int **g;
};

typedef struct cityADT cityADT;

void create(cityADT *);
void display(cityADT *);
void BFS(cityADT *);
void DFS(cityADT *);

