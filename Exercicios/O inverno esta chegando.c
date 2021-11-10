#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int idade, idade_arq = 999;
    float altura, maior_altura = 0, maior_altura_espa = 0;
    char casa, gene, habi, sexo_espada = 'X';
    int menor_idade_arq = 999, qtde_soldados = 0, qtde_lanc = 0;
    while(1){
        scanf(" %c", &casa);
        if(casa != 'S' && casa != 'P' && casa != 'C' && casa != 'O'){
            break;
        }
        scanf(" %c", &gene);
        scanf("%d", &idade);
        scanf("%f", &altura);
        scanf(" %c", &habi);
        qtde_soldados ++;
        if(casa == 'C'){
            if(altura > maior_altura){
                maior_altura = altura;
            }
        }
        if(casa == 'S'){
            if(habi == 'l'){
                qtde_lanc ++;
            }
        }
        if(casa == 'O'){
            if(habi == 'a'){
                if(idade < idade_arq){
                    idade_arq = idade;
                }
            }
        }
        if(casa == 'P'){
            if(habi == 'e'){
                if(altura > maior_altura_espa){
                    maior_altura_espa = altura;
                    sexo_espada = gene;
                }
            }
        }
        qtde_soldados ++;

    }

    printf("%d\n", qtde_soldados/2);
    printf("%.2f\n", maior_altura);
    printf("%d\n", qtde_lanc);
    printf("%d\n", idade_arq);
    printf("%c\n", sexo_espada);
}