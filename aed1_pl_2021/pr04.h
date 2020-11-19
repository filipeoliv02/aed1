//
// Created by Bruno on 22/10/2020.
//

#ifndef AED1_PR04_H
#define AED1_PR04_H

#define KEY_INDEX_RADIX 4

/**
 *  Structure used for key-index-count, LSD, MSD and other
 */
typedef struct {
    char ** str; // array of strings
    int * len; // array of string lengths
    int N; // number of strings (size of array of strings)
} StringElementsArray;

void worksheet3E1 (void);
void createStringElementsArray(StringElementsArray * si, int N);
void key_index_counting(StringElementsArray * a, int * keys, int R);
void createStringElementsArrayAndFill(StringElementsArray * si, int N, char ** strings);
void freeStringElementsArray(StringElementsArray * si);

int main_pr04(int argc, char * argv[]);

#endif //AED1_PR04_H