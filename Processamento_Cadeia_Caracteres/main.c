#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "ForcaBruta.h"
#include "BMH.h"
#include "BMHS.h"
#include "ShiftAndAproximado.h"
#include "ShiftAndExato.h"


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

  clock_t p0, p1; 
  
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
    
  
  p0 = clock;  
  scanf("%*[^\n]"); getchar();
  printf(" Forca bruta: ");
  ForcaBruta(T, n, P, m);
  scanf("%*[^\n]"); getchar();
  printf("\nTempo -> %i segundos\n", (double)(p1-p0)/CLOCKS_PER_SEC);
  p1= clock;

  
  p0 = clock;  
  printf(" BMH: ");
  BMH(T, n, P, m);
  scanf("%*[^\n]"); getchar();
  printf("\nTempo -> %i segundos\n", (double)(p1-p0)/CLOCKS_PER_SEC);
  p1= clock;
  
  
  p0 = clock;  
  printf(" BMHS: ");
  BMHS(T, n, P, m);
  scanf("%*[^\n]"); getchar();
  printf("\nTempo -> %i segundos\n", (double)(p1-p0)/CLOCKS_PER_SEC);
  p1= clock;
  
  
  p0 = clock;  
  printf(" Shift-And-Exato: ");
  ShiftAndExato(T, n, P, m);
  scanf("%*[^\n]"); getchar();
  printf("\nTempo -> %i segundos\n", (double)(p1-p0)/CLOCKS_PER_SEC);
  p1= clock;
  
  
  p0 = clock;  
  printf(" Shift-And-Aproximado \n");
  printf("Numero de erros: ");
  scanf("%ld%*[^\n]", &k); getchar();
  ShiftAndAproximado(T, n, P, m, k);
  printf("\nTempo -> %i segundos\n", (double)(p1-p0)/CLOCKS_PER_SEC);
  p1= clock;
  
  
  return 0;
}
