#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float h, a, b;
    float vol;
    scanf("%f", &h);
    scanf("%f", &a);
    scanf("%f", &b);
    vol = h/3*(pow(b,2)+sqrt(pow(b,2)*pow(a,2))+pow(a,2));
    printf("%.1f\n", vol);
	return 0;
}