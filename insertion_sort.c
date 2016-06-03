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
    for (i = 1; i < n; ++i)
    {
        for (j = i; j > 0 && a[j] < a[j - 1]; --j)
        {
            swap(a, j, j - 1);
        }
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

int main(int argc, const char *argv[])
{
    int a[] = { 5, 1, 8, 2, 7, 3, 9, 4, 6 };
    print(a, 9);
    sort(a, 9);
    assert(is_sorted(a, 9));
    print(a, 9);
    return 0;
}
