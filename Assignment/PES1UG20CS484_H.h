typedef struct node
{
    int data;
    int x_coord;
    int y_coord;
    struct node *right, *down;
}node;

typedef struct matrix
{
    node *head[10];
}matrix;

typedef struct Stack
{
        int x_data[10];
        int y_data[10];
        int top;
}stack;
void init(matrix *pm, stack* ps);
void create(matrix *pm, int *px1, int *py1, int *px2, int *py2);
void walk(matrix *pm, int x1, int y1, int x2, int y2,stack* ps,int* ox,int* oy);
