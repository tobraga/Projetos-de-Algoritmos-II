#include <stdio.h>
#include <stdlib.h>


#define MAXTAMTEXTO     1000
#define MAXTAMPADRAO    10
#define MAXCHAR         256
#define NUMMAXERROS     10
typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

TipoTexto T;
TipoPadrao P;
long n, m, k, i;

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m)
{ long i, j, k;
  for (i = 1; i <= (n - m + 1); i++) 
    { k = i;  j = 1;
      while (T[k-1] == P[j-1] && j <= m) { j++; k++; }
      if (j > m) printf("Casamento na posicao: %3ld\n", i);
    }
}
