#include <stdio.h>
#include <stdlib.h>
 
static void heapify(int *v, int i, int size)
{
    int left;
    int right;
    int largest;
    while (i < size)
    {
        left = (i * 2) + 1;
        right = (i * 2) + 2;
        largest = i;
        if (left < size && v[left] > v[largest])
        {
            largest = left;
        }
        if (right < size && v[right] > v[largest])
        {
            largest = right;
        }
        if (i == largest)
        {
            break;
        }
        int swp = v[i];
        v[i] = v[largest];
        v[largest] = swp;
        i = largest;
    }
}
 
static void make_heap(int *v, int size)
{
    int i;
    for (i = size / 2; i >= 0; i--)
    {
        heapify(v, i, size);
    }
}
 
void heap_sort(int *v, int size)
{
    int i;
    make_heap(v, size);
    for (i = size - 1; i > 0; i--)
    {
        int swp = v[i];
        v[i] = v[0];
        v[0] = swp;
        heapify(v, 0, i);
    }
}
 
 
int busca_binaria(int *v, int l, int r, int chave)
{
    int  m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (chave < v[m])
        {
            r = m - 1;
        }
        else if (chave > v[m])
        {
            l = m + 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}
 
int main()
{
    int n, q, x;
    scanf("%d %d", &n, &q);
    int *v = malloc(n * sizeof(int));
    int *h = malloc(q * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &h[i]);
    }
 
    heap_sort(v, n);
 
    int aux,aux1,aux2;
 
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",v[i]);
    // }
    // printf("\n");
 
    for (int i = 0; i < q; i++)
    {
        aux = busca_binaria(v, 0,n, h[i]);
        if (aux == -1)
        {
            printf("-1\n");
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                x = busca_binaria(v,0, aux-1, h[i]);
                if (x == -1)
                {
                    aux1 = aux;
                    break;
                }
                else
                    aux1 = x;
            }
            for (int j = 0; j < n; j++)
            {
                x = busca_binaria(v,aux+1,n-1, h[i]);
                if (x == -1)
                {
                    aux2 = aux;
                    break;
                }
                else
                    aux2 = x;
            }
            printf("%d %d\n",aux1 +1,aux2+1);
        }
    }
    free(v);
    free(h);
    return 0;
}