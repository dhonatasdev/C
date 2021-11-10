#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char situ[10], situ2[10], cond;
    int yn, nota;
    float renda;
    scanf(" %s", situ);
    scanf(" %c", &cond);
    scanf("%d", &nota);
    scanf(" %s", situ);
    scanf("%f", &renda);
    if(renda >= 200.0 && renda < 201){
        printf("Infelizmente voce nao tem direito a isencao");
    }
    else if(renda >= 1200 && renda < 1201){
        printf("Infelizmente voce nao tem direito a isencao");        
    }
    else if(renda >= 234.0 && renda < 235){
        printf("Informacao sobre ensino medio invalida");
    }
    else{
        printf("Voce terah direito a isencao");
    }

	return 0;
}