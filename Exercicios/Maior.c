#include <stdio.h>

int maiorprimo(){
    int maior, veri = 0;
    int n;
    int i;
    int c = 0;
    int s = 0;
    int aux[100];

    while(1){
        scanf("%d", &n); 
        if(n==404) break;
    for(i=1; i<=n; i++){ //pra conferir se o 
        if(n%i==0){
            c+=1;
        }
    }
    if(c==2){  // se for primo, ele vai ser colocado no vetor auxiliar
        aux[s]= n;
        s+=1;
    }
    c = 0;
    }
    
    maior = aux[0];
    for(i=0; i<s; i++){
        if(maior<aux[i])
        maior = aux[i];
        veri = 1;
    }
    if(veri==0) printf("SEM PRIMOS\n");
    else printf("%d\n", maior);
    return 0;
}
int main(){
    maiorprimo();
    return 0;
}