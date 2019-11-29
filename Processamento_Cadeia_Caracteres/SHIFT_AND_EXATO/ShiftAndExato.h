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


void ShiftAndExato(TipoTexto T, long n, TipoPadrao P, long m)
{ long Masc[MAXCHAR], i, R = 0;
  for (i = 0; i < MAXCHAR; i++) 
    Masc[i] = 0;
  for (i = 1; i <= m; i++) 
    Masc[P[i-1] + 127] |= 1 << (m - i);
  for (i = 0; i < n; i++) 
    { R = ((((unsigned long)R) >> 1) | 
          (1 << (m - 1))) & Masc[T[i] + 127];
      if ((R & 1) != 0)
      printf(" Casamento na posicao %3ld\n", i - m + 2);
    }
}
