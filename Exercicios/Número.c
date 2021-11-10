#include <stdio.h>




int main(){

    int n, i, s, c, p;
    i =1;

    s = 0;

    scanf("%d", &p);

    for(c=1; c<=p; c++) {

    scanf("%d", &n);

    while(s<n){

        if(n%i == 0){

            s = s+i;

        }

        i++;

    }

    if(s==n) printf("%d eh perfeito\n", n);

    else printf("%d nao eh perfeito\n", n);

    i =1;

    s = 0;

    }

    return 0;

}

    