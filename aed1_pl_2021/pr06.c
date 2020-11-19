#include "pr06.h"


void createStringElementsArrayIdx(StringElementsArray * a, int N){
    //Igual a createStringElementsArray....
    int * index = (int*) malloc (sizeof(int) * N);
}

int msd_sort_whithout_cutoff(StringElementsArrayIdx *a, StringElementsArrayIdx *aux, int lo, int hi, int d, int R) {
    static int ordem_chamada_rec = 1;
    static int d_max = 0;
    int i,r,c;
    int * count = newIntArray(R + 2);

    //StringElementsArray aux;
    createStringElementsArrayIdx(aux, a->s.N);

    // reset count[] array
    for (i = 0; i < R+2; i++)
        count[i]=0;

    if (hi <= lo) return d_max;


    //if (hi - lo <= cutoff_value) insertion_sort();

    // compute frequency counts
    for (i = lo; i <= hi; i++) {
        c = charAt(a, i, d);
        count[c + 2]++;
    }

    // transform counts to indicies
    for (r = 0; r < R + 1; r++)
        count[r+1] += count[r];

    // distribute
    for (i = lo; i <= hi; i++) {
        c = charAt(a, i, d);
        aux->s.str[count[c + 1]] = a->s.str[i];
        aux->s.len[count[c + 1]] = a->s.len[i];
        aux->index[count[c + 1]] = a->index[i];
        count[c + 1]++;
    }

    // copy back
    for (i = lo; i <= hi; i++) {
        a->s.str[i] = aux->s.str[i-lo];
        a->s.len[i] = aux->s.len[i-lo];
        a->index[i] = aux->index[i-lo];
    }

    // Trace of recursive calls for MSD string sort (version with no cutoff for small subarrays used!)
    printf("\n-------------\nMSD Sorted List (left to right) after iteration (lo,hi,d,ordem)= %d,%d,%d,%d:\n",lo,hi,d,ordem_chamada_rec++);
    for (i = lo; i <= hi; i++)
        printf("\t%s\n",a->s.str[i]);
    if (d > d_max) d_max = d;

    // recursively sort for each character
    for (r = 0; r < R; r++)
        msd_sort_whithout_cutoff(a, aux, lo + count[r], lo + count[r+1] - 1, d+1, R);
    return d_max;
}

int charAt(StringElementsArrayIdx * a, int i, int d) {
    return (d < a->s.len[i]) ? (a->s.str[i][d]) : STRING_END_CHAR;
}
