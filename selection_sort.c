#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void swap(int *a, int m, int n)
{
    int aux = a[m];
    a[m] = a[n];
    a[n] = aux;
}

bool is_sorted(int *a, int n)
{
    int i;
    for (i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            return false;
        }
    }
    return true;
}

void sort(int *a, int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        int min = i;
        for (j = i + 1; j < n; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a, i, min);
    }
}

void print(int *a, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = { 5, 1, 8, 2, 7, 3, 9, 4, 6 };
    print(a, 9);
    sort(a, 9);
    assert(is_sorted(a, 9));
    print(a, 9);
    return 0;
}
