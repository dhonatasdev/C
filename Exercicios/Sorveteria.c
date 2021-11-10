#include <stdio.h>
#include <string.h>

int main(){
    int n, veri = 0;
    char op[31];
    scanf(" %[^\n]s", op);
    scanf("%d", &n);
    if(strcasecmp(op, "cereja")==0 || strcasecmp(op, "morango")==0){
        if(n>2){
            printf("%.2f\n", n*4.50);
            printf("COM CALDA\n");

            veri = 1;
        }
        else{
            printf("%.2f\n", n*4.50);
            printf("SEM CALDA\n");
            veri = 1;
        }
    }
    if(strcasecmp(op, "damasco")==0 || strcasecmp(op, "siriguela")==0){
        if(n>2){
            printf("%.2f\n", n*3.80);
            printf("COM CALDA\n");
            veri = 1;
        }
        else{
            printf("%.2f\n", n*3.80);
            printf("SEM CALDA\n");
            veri = 1;
        }
    }
    if(veri == 0) {
        if(n>2){
            printf("%.2f\n", n*2.75);
            printf("COM CALDA\n");
        }
        else {
            printf("%.2f\n", n*2.75);
            printf("SEM CALDA\n");
        }
    }
}