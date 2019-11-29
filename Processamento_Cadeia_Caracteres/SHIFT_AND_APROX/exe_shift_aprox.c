#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "ShiftAndAproximado.h"

#define MAXTAMTEXTO     1000
#define MAXTAMPADRAO    10
#define MAXCHAR         256
#define NUMMAXERROS     10
typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

TipoTexto T;
TipoPadrao P;
long n, m, k, i;




int main(int argc, char **argv){

    
  printf(" Tamanho do texto: ");
  scanf("%ld%*[^\n]", &n); getchar();
  printf(" Tamanho do padrao: ");
  scanf("%ld%*[^\n]", &m); getchar();
  
  printf(" Texto: ");
  for (i = 1; i <= n; i++) 
    { T[i-1] = getchar();
      if (T[i-1] == '\n')
      T[i-1] = ' ';
    }  
  scanf("%*[^\n]");
  getchar();
  printf(" Padrao: ");
  for (i = 1; i <= m; i++) 
    { P[i-1] = getchar();
      if (P[i-1] == '\n')
      P[i-1] = ' ';
    }
    
  clock_t timer; 
  timer = clock();
 
  printf(" Shift-And-Aproximado \n");
  printf("Numero de erros: ");
  scanf("%ld%*[^\n]", &k); getchar();
  ShiftAndAproximado(T, n, P, m, k);
  timer= clock() - timer;
  printf("\nTempo -> %f segundos\n", ((float)timer)/CLOCKS_PER_SEC);

}
