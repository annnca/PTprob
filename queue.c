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

void print(int *a, int *sq, int *eq)
{
    if(!is_empty_queue(&sq, &eq)){
        int i;
        for (i = *sq; i <= *eq; ++i)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    } else {
        printf("empty list");
    }
}
int main ()
{
    int sq, eq, q[50], Max = 50;
    initialise_queue(&sq, &eq);
    add_to_queue(q, &sq, &eq, Max, 1);
    add_to_queue(q, &sq, &eq, Max, 2);
    add_to_queue(q, &sq, &eq, Max, 3);
    add_to_queue(q, &sq, &eq, Max, 4);
    print(q, &sq, &eq);
    pop_queue(&sq, &eq, Max);
    print(q, &sq, &eq);
    printf("\n%d", queue_front(q, &sq));
}
