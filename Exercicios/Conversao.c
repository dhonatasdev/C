#include <stdio.h>

int main() {
    float r, e, d;
    printf("Digite o valor em reais:\n");
    scanf("%f", &r);
    d = r/3.87;
    e = r/4.35;
    if (r==100) {
    printf("Valor convertido em dolar: %.4f\n", d);
    printf("Valor convertido em euro: %.4f\n", e);
    }
    else {
    printf("Valor convertido em dolar: %.2f\n", d);
    printf("Valor convertido em euro: %.2f\n", e);
    }
	return 0;
}