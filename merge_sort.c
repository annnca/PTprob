
#include<stdio.h>

void interclasare(int *x,int *v,  int sx, int fx, int sy, int fy)
{
    int t;
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
		for (t = i;t <= fx;++t)
			v[++k] = x[t];

	for (i = 1;i <= k;i++)
		x[sx + i - 1] = v[i];

}

void mergesort(int *x,int *v, int s, int f)
{
	if (s != f)
	{
		mergesort(x,v,  s, (s + f) / 2);
		mergesort(x,v, (s + f) / 2 + 1, f);
		interclasare(x,v, s, (s + f) / 2, (s + f) / 2 + 1, f);
	}
}
void print(int *a, int n)
{
    int i;
    for (i = 1; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int v[50];
    int a[] = { 5, 1, 8, 2, 7, 3, 9, 4, 6 };
    print(a, 9);
    mergesort(a, v,0,9);
    print(v, 9);
    return 0;
}
