#include <stdio.h>
int main(){
    float valor;
    float soma = 0;
    int qtde = 0;
    while(1){
        scanf("%f", &valor);
        if(valor<0){
            break;
        }
        soma +=valor;
        qtde += 1;
    }
    printf("%.2f\n", soma);
    if(soma>0){
    printf("%.2f\n", soma/qtde);
    }
    else {
        printf("0.00\n");
    }
}
