#include <stdio.h>
#include <stdlib.h>

static void merge(int *v, int *v1, int *v2, int size) {

    int size_v1 = size / 2;
    int size_v2 = size - size_v1;
    int i = 0;
    int j = 0;
    int k = 0;

    /** Enquanto não chegar ao fim da primeira
     *  e da segunda metade **/
    for (i = 0; j < size_v1 && k < size_v2; i++) {
        /* Se o elemento da primeira metade
         * é menor ou igual ao da segunda metade,
         * insira-o no vetor resultado
         */
        if (v1[j] <= v2[k]) {
            v[i] = v1[j++];
        }
        /* Caso contrário, insira o elemento da
         * segunda metade no vetor resultado */
        else {
            v[i] = v2[k++];
        }
    }

    /** Se ainda  restam elementos na primeira partição **/
    while (j < size_v1) {
        /* Copiamos os elementos para o vetor resultado */
        v[i++] = v1[j++];
    }
    /** Se ainda  restam elementos na segunda partição **/
    while (k < size_v2) {
        /* Copiamos os elementos para o vetor resultado */
        v[i++] = v2[k++];
    }
}

void merge_sort(int *v, int size) {
    int mid;
    if (size > 1) {
        mid = size / 2;
        /* aloca espaço para os subvetores */
        int *v1 = malloc(sizeof(int) * mid);
        int *v2 = malloc(sizeof(int) * size - mid);
        /* Copia os elementos de v para os subvetores */
        int i;
        for (i = 0; i < mid; i++) {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++) {
            v2[i - mid] = v[i];
        }
        /* Ordena recursivamente a primeira metade */
        merge_sort(v1, mid);
        /* Ordena recursivamente a segunda metade */
        merge_sort(v2, size - mid);
        /* Faz a junção das duas metades */
        merge(v, v1, v2, size);
        /* Libera o espaço alocado */
        free(v1);
        free(v2);
    }
}

int busca_binaria(int* v,int n,int chave){
    int l,r,m;
    l = 0;
    r = n-1;
    while(l<=r){
        m = (l+r)/2;
        if(chave<v[m]){
            r = m-1;
        }
        else if(chave>v[m]){
            l = m+1;
        }
        else{
            return m;
        }
    }
    return -1;
}

int main()
{
    int n;
    int c,chave,aux,count;
    scanf("%d %d", &n, &c);
    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    merge_sort(v,n);
    for (int i = 0; i < n; i++)
    {
        count = 0;
        chave = c - v[i];
        aux = busca_binaria(v,n,chave);
        if(i == aux){
            count = 1;
        }
        else if(aux != -1)
        {
            printf("%d %d\n",i+1,aux+1);
            break;
        }else{
            count = 1;
        }
    }
    if(count){
        printf("-1\n");
    }
    return 0;
}