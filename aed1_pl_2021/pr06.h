#ifndef AED1_PR06_H
#define AED1_PR06_H

#define  STRING_END_CHAR -1
#define CHAR_8BIT_RADIX 256
#include "pr04.h"
#include <stdlib.h>

typedef struct {
    StringElementsArray s;
    int *index;
}StringElementsArrayIdx;

void createStringElementsArrayIdx(StringElementsArray * a, int N);
int msd_sort_whithout_cutoff(StringElementsArrayIdx *a, StringElementsArrayIdx *aux, int lo, int hi, int d, int R);

#endif //AED1_PR06_H
