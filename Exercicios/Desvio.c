#include<stdio.h>
int main(void) 
{
  int n, c;
  double des, num, med;
  double *vetNum;
  med = 0;
  des = 0;
  scanf("%d", &n);
  vetNum = (double *)malloc(n * sizeof(double));
  for (c = 0; c < n; c++)
  {
    scanf("%lf", &num);
    med += num;
    vetNum[c] = num;
  }
  med = (double)med / n;
  for (c = 0; c < n; c++)
  {
    des = des + (vetNum[c] - med) * (vetNum[c] - med);
  }
  des = sqrt((double) (des/n));
  printf("\n%.2lf", des);
  free(vetNum);
  scanf("%d", c);
  return 0;
}