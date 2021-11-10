#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0){
        printf("E");
    }
    if(n>=1 && n<=35){
        printf("D");
    }
    else if(n>=36 && n<=60){
        printf("C");
    }
    else if(n>=61 && n<=85){
        printf("B");
    }
    if(n>85) printf("A");
	return 0;
}