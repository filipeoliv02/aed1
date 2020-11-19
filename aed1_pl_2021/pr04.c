//
// Created by Bruno on 22/10/2020.
//

#include "pr04.h"
#include "../libs_src/lib_util.h"

int main_pr04(int argc, char * argv[]) {
    worksheet3E1();
    return 0;
}

void worksheet3E1 (void) {
   
}

void createStringElementsArray(StringElementsArray * si, int N) {
    si->N = N;
    si->str = (char **) malloc(sizeof(char *)*N);
    si->len = (int *) malloc(sizeof(int)*N);
}

void key_index_counting(StringElementsArray * a, int * keys, int R) {
    int i,r,c;
    int N = a->N;
    int * count = newIntArray(R + 1);
    for (i = 0; i < R + 1; i++)
        count[i]=0; // reset count[] array
    StringElementsArray aux; // aux Array
    createStringElementsArray(&aux,N); // create aux array
    int * aux_keys = newIntArray(N);

    // compute frequency counts
    for (i = 0; i < N; i++)
        count[keys[i]]++;

    // transform counts to indicies
    for (r = 0; r < R; r++)
        count[r+1] += count[r];

    // distribute
    for (i = 0; i < N; i++) {
        c = keys[i] - 1;
        aux.str[count[c]] = a->str[i];
        aux.len[count[c]] = a->len[i];
        aux_keys[count[c]] = keys[i];
        count[c]++;
    }

    // copy back
    for (i = 0; i < N; i++) {
        a->str[i] = aux.str[i];
        a->len[i] = aux.len[i];
        keys[i] = aux_keys[i];
    }

    freeIntArray(count);
    freeIntArray(aux_keys);
    freeStringElementsArray(&aux);
}

void createStringElementsArrayAndFill(StringElementsArray * si, int N, char ** strings){
    int i;
    createStringElementsArray(si, N);
    for (i = 0; i < N; i++) {
        si->str[i] = strings[i];
        si->len[i] = (int)strlen(strings[i]);
    }

}

void freeStringElementsArray(StringElementsArray * si) {
    free(si->str);
    free(si->len);
    return;
}