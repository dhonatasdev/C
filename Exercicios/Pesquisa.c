#include<stdio.h>
#include <string.h>
int main(){
    int qtde_mulher = 0, qtde_zomi = 0, compradores = 0, menor = 9999, idade, temp;
    float compras, soma_compras = 0;
    char genero, filme;
    while(1){
        scanf("%d", &idade);
        if(idade <= 0){
            break;
        }
        temp = idade;
        scanf(" %c", &genero);
        scanf("%f", &compras);
        scanf(" %c", &filme);
        if(genero == 'f' && compras <= 100){
            qtde_mulher ++;
        }
        if(genero == 'm' && filme == 'f' || genero == 'm' && filme == 't'){
            qtde_zomi += 1;
        }
        if(menor >= temp){
            menor = temp;
        }
        soma_compras += compras;
        compradores ++;
    }
    if(compradores == 0){
        printf("0");
    }
    else{
        printf("%d\n", qtde_mulher);
        printf("%d\n", menor);
        printf("%.2f\n", soma_compras/compradores);
        printf("%d\n", qtde_zomi);
    }
}