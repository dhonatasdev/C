#include<stdio.h>

int main()
{
  int num, maior = 0, menor = 0, y=0, n;
 
    scanf("%d",&n); 
    scanf("%d",&num);
   
  menor = num;
  maior = num;
 
  for( y = 1; y < n; y++ ){
   
    scanf("%d",&num);
 
    if(num > maior) maior = num;
    if(num < menor) menor = num;
   
  }

  printf ("%d\n",menor);
 
  return 0;
 
}
