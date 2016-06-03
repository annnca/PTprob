#include<stdio.h>
#include <stdbool.h>


#define V 4

void printSolution(int color[]);

bool isSafe (int v, bool graph[V][V], int color[], int c)
{
    int i;
    for (i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}


bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{

    if (v == V)
        return true;

    int c;
    for (c = 1; c <= m; c++)
    {

        if (isSafe(v, graph, color, c))
        {
           color[v] = c;


           if (graphColoringUtil (graph, m, color, v+1) == true)
             return true;

           color[v] = 0;
        }
    }

    /* If no color can be assigned to this vertex then return false */
    return false;
}

bool graphColoring(bool graph[V][V], int m)
{
    int i;

    int color[50] ;
    for ( i = 0; i < V; i++)
       color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == false)
    {
      printf("Solution does not exist");
      return false;
    }


    printSolution(color);
    return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
    int i;
    printf("Solution Exists:"
            " Following are the assigned colors \n");
    for ( i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");
}

int main()
{

    bool graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    graphColoring (graph, m);
    return 0;
}
