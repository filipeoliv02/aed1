#include "tp_week7.h"

int main_tp_week7(int argc, char *argv[]) {
  printf("Aula TP de 28 outubro de 2020\n");
  ficha1_exe7();

  return 0;
}

void ficha1_exe7() {
  int a[] = {3, 5, 10, 12}, na = 4, ia = 0;

  int b[] = {4, 5, 8, 10}, nb = 4, ib = 0;

  int last, cur;
  last = a[0] < b[0] ? a[0] : b[0];
  printf("%d ", last);
  while (ia < na || ib < nb) {
    if (ia < na && ib < nb) {
      if (a[ia] < b[ib]) {
        cur = a[ia];
        ia++;
      } else {
        cur = b[ib];
        ib++;
      }
    } else if (ia < na) {
      cur = a[ia];
      ia++;
    } else {
      cur = b[ib++];
    }
    if (cur != last)
      printf("%d ", cur);
  }
}

/*Exercicio 15.1
i) M>>N
ii) N>>M
iii) M, N mesma ordem -> H1, H3
Algoritmos
- Custo de Ordenação
   O(N.log N)
- Pesquisa Binária
   O(log2(N))
- Pesquisa Sequencial
   O(N)

H1: pesquisa sequencial em a[] desordenado e para cada
palavra verificar se existe em w usando
pesquisa binária

0(N.log2(M))


H2: ordenação de a[] e fusão entre a[] e w[] de modo linear

O([N.log(N)] + [N+M])
O([ordenação de a[]] + [fusão])


H3: ordenação de a[] + pesquisa sequencial em w[] e para cada
palavra pesquisa binária em a[]

O(N.log(N) + M.log2(N))




*/
