#include <stdio.h>
#include <stdlib.h>

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
    int n,m;
    scanf("%d", &n);
    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    scanf("%d",&m);
    int *k = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&k[i]);
    }

    
    return 0;
}