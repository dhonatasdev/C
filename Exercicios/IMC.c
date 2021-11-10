#include <stdio.h>
int main() {
    float p, a;
    scanf("%f", &p);
    scanf("%f", &a);
    printf("%.1f\n", p/pow(a,2));
	return 0;
}