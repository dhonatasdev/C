#include <stdio.h>

int main(void) {
 int contador1 = 0, convidados, convidado1, somaTOTAL = 0 ;
 float preco, precoTOTAL = 0  ;


 /*scanf ("%d", &convidados);
 if (convidados <= 15 ) preco = 0, convidados = convidados ;
  else 
    if (convidados >= 25) convidados = 25 , preco = 420;
      else
          if (convidados > 15 && convidados < 25) preco = ((convidados - 15) * 42), convidados = convidados; 
  somaTOTAL = somaTOTAL +  convidados;
  precoTOTAL = precoTOTAL + preco;*/
 
 while (1){
   scanf ("%d", &convidados);
   if(convidados < 0){
     break;
   }
   if (convidados <= 15 ) preco = 0, convidados = convidados  ;
    else 
     if (convidados > 25) convidados = 25 , preco = 420;
      else
          if (convidados > 15 && convidados <=25) preco = (( convidados - 15) * 42); 

   somaTOTAL = somaTOTAL +  convidados;
   precoTOTAL = precoTOTAL + preco; 
   contador1 ++;
   
   }
       
printf ("%.2f\n", precoTOTAL);
printf ("%d\n", contador1 + somaTOTAL );


  return 0;
}