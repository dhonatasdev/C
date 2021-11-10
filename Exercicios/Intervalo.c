#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int i;
    for(i=n1; i<=n2; i++){
        printf("%d\n", i);
    }
	return 0;
}