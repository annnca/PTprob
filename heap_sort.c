#include<stdio.h>
#include<stdlib.h>

typedef struct node  {
    int data;
    struct node *l;
    struct node *r;
} node_heap;
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
int main() {

    int x[] = {6,1,8,3,10,9,7,4,2,5}, sorted[50], i;
    int n=sizeof(x)/sizeof(x[0]);
    struct node *root = (node_heap*)malloc(sizeof(node_heap));
    root->l = NULL;
    root->r = NULL;
    root->data = x[0];

    for(i = 1; i < n; i++) {
        add_to_heap(root, x[i]);
    }

    n = 0;
    heap_sort(root,sorted, &n);
    for(i = 1; i <= n; i++ ) {
        printf("%d " ,sorted[i]);
    }
}
