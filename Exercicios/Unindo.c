#include <stdio.h>

int main()
{
    int n1, n2, i;
    scanf("%d", &n1);
    if(n1==0) printf("Erro - A lista deve ter pelo menos 1 elemento.");
    int list[n1];
    for(i=0; i<n1; i++) {
        scanf("%d", &list[i]);
    }
    scanf("%d", &n2);
    int lista[n2];
    if (n1!=0){
    if(n2==0) printf("Erro - A lista deve ter pelo menos 1 elemento.");
    for(i=0; i<n2; i++) {
        scanf("%d", &lista[i]);
    }
    if(n1!=0&&n2!=0){
    for(i=0; i<n1; i++){
        printf(" %d", list[i]);
    }
    }
    if(n2!=0&&n2!=0){
    for(i=0; i<n2; i++){
        printf(" %d", lista[i]);
    }
    }
    return 0;
}}