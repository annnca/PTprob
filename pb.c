/*Parcurgere in latime
Se considera un graf orientat cu N varfuri si M arce.

Cerinta
Fiind dat un nod S, sa se determine, pentru fiecare nod X, numarul minim de
 arce ce trebuie parcurse pentru
 a ajunge din nodul sursa S la nodul X.

Date de intrare
Fisierul de intrare bfs.in contine pe prima linie 3 numere intregi N M S,
cu semnificatia din enunt. Urmatoarele M linii contin cate doua numere x y,
 cu semnificatia ca exista arc orientat de la x la y.

Date de iesire
In fisierul de iesire bfs.out se vor afla N numere separate prin spatiu cu s
emnificatia ca al i-lea numar reprezinta numarul minim de arce ce trebuie
 parcurse de la nodul S la nodul i.*/
#include<stdio.h>
#include<stdlib.h>

struct node_heap
{
    int data;

    struct node_heap *l, *r;
};

typedef struct node_heap node_heap;

struct node_list
{
    int data;
    struct node_list *next;
};

typedef struct node_list node_list;


void swap(int *a, int *b)
{
    int p = *a;
    *a = *b;
    *b = p;
}

void interclasare(int *x, int *v, int sx, int fx, int sy, int fy)
{int t;
    int i = sx, j = sy, k = 0;
    while (i <= fx && j <= fy)
    {
        if (x[i] <= x[j])
        {
            v[++k] = x[i];
            ++i;
        }
        else
        {
            v[++k] = x[j];
            ++j;
        }
    }
    if (i>fx)
        for (t = j;t <= fy;++t)
            v[++k] = x[t];
    if (j>fy)
        for ( t = i;t <= fx;++t)
            v[++k] = x[t];

    for ( i = 1;i <= k;i++)
        x[sx + i - 1] = v[i];

}

void mergesort(int *x, int *v, int s, int f)
{
    if (s != f)
    {
        mergesort(x, v, s, (s + f) / 2);
        mergesort(x, v, (s + f) / 2 + 1, f);
        interclasare(x, v, s, (s + f) / 2, (s + f) / 2 + 1, f);
    }
}


void quicksort(int *v, int x, int y)
{
    if (x < y)
    {
        int mid = (x + y) / 2;
        int piv = v[mid];
        int i = x, j = y;

        while (i <= j)
        {
            while (v[i] < piv)
                ++i;
            while (v[j] > piv)
                --j;

            if (i <= j)
            {
                swap(&v[i], &v[j]);
                ++i, --j;
            }
        }

        quicksort(v, x, j);
        quicksort(v, i, y);
    }

}


void initialise_heap(node_heap **root, int data)
{
    *root = (node_heap*)malloc(sizeof(node_heap));

    (*root)->data = data;
    (*root)->l = NULL;
    (*root)->r = NULL;
}


void add_to_heap(node_heap *root, int data)
{
    if (data < root->data)
    {
        if (root->l == NULL)
        {
            node_heap *temp_node_heap = (node_heap*)malloc(sizeof(node_heap));
            temp_node_heap->data = data;
            temp_node_heap->l = 0;
            temp_node_heap->r = 0;

            root->l = temp_node_heap;

        }
        else
            add_to_heap(root->l, data);
    }
    else
    {
        if (root->r == NULL)
        {
            node_heap *temp_node_heap = (node_heap*)malloc(sizeof(node_heap));
            temp_node_heap->data = data;
            temp_node_heap->l = 0;
            temp_node_heap->r = 0;

            root->r = temp_node_heap;
        }
        else
            add_to_heap(root->r, data);
    }

}

void heap_sort(node_heap *root, int *vec, int *size)
{
    if (root->l != 0)
        heap_sort(root->l, vec, size);

    *size = *size + 1;
    vec[*size] = root->data;

    if (root->r != 0)
        heap_sort(root->r, vec, size);
}

void initialise_list(node_list **node)
{
    *node = NULL;
}

void add_to_list(node_list** node, int data)
{
    node_list *p = (node_list*)malloc(sizeof(node_list));
    p->data = data;
    p->next = *node;
    *node = p;
}
void remove_first_list(node_list **node)
{
    if (node)
    {
        node_list *p = *node;
        *node = p->next;
        free(p);
    }
}

int get_first_elem_list(node_list *node)
{
    if (node)
        return node->data;

    return -1;
}

void initialise_queue(int *sq, int *eq)
{
    *sq = *eq = -1;
}

void add_to_queue(int *queue, int *sq, int *eq, int MAX, int data)
{
    if (*sq == (-1) && *eq == (-1))
        *sq = *eq = 1, queue[*eq] = data;
    else
    {
        int t = (*eq + 1) % (MAX - 1);
        if (t == 0)
            t = 1;
        queue[t] = data;
        *eq = t;
    }
}
int is_empty_queue(int *sq, int *eq)
{
    if (*sq == (-1) && *eq == (-1))
        return 1;
    else
        return 0;
}
void pop_queue(int *sq, int *eq, int MAX)
{
    int t = (*sq + 1) % (MAX - 1);
    if (t == 0)
        t = 1;
    *sq = t;
    if (*sq > *eq)
        *sq = *eq = -1;
}

int  queue_front(int *queue, int *sq)
{
    return queue[*sq];
}

void DFS(node_list *V[], int *viz, int t)
{
    viz[t] = 1;
    while (V[t])
    {
        if (!viz[V[t]->data])
            DFS(V, viz, V[t]->data);
        remove_first_list(&V[t]);
    }
}

int  cost[100010];

void BFS(node_list *V[], int size, int *viz, int s)
{
    int *queue = (int*)malloc(sizeof(int) * size);
    int sq, eq;

    initialise_queue(&sq, &eq);

    add_to_queue(queue, &sq, &eq, size + 1, s);

    while (!is_empty_queue(&sq, &eq))
    {
        int node = queue_front(queue, &sq);
        viz[node] = 1;
        int el;
        do
        {
            el = get_first_elem_list(V[node]);
            if (el != -1)
            {
                if (!viz[el])
                {
                    viz[el] = 1;
                    add_to_queue(queue, &sq, &eq, size + 1, el);
                    if(el!=s)
                        cost[el] = cost[node] + 1;
                }
                remove_first_list(&V[node]);
            }
        } while (el != -1);

        pop_queue(&sq, &eq, size + 5);
    }

    free(queue);
}

void sort_top(node_list *V[], int *viz, node_list **stk, int t)
{
    viz[t] = 1;
    node_list *p = V[t];
    while (p)
    {
        if (!viz[p->data])
        {
            viz[p->data] = 1;
            sort_top(V, viz, stk, p->data);
        }
        p = p->next;
    }
    add_to_list(stk, t);

}

FILE *in, *out;

node_list *A[100010];
int N, M, viz[100010];

int main()
{
    in = fopen("bfs.in", "r");
    out = fopen("bfs.out", "w");

    int S;

    fscanf(in, "%d%d%d", &N, &M, &S);

    int j, k,i;

    for (i = 1, j, k;i <= M;i++)
    {
        fscanf(in, "%d%d", &j, &k);
        add_to_list(&A[j], k);
    }
    BFS(A, N, viz, S);

    for ( i = 1;i <= N;i++)
    {
        if (viz[i])
            fprintf(out, "%d ", cost[i]);
        else
            fprintf(out, "-1 ");
    }


    return 0;
}
