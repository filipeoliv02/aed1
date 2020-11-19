//
// Created by André Pinto on 16/09/19.
//
#include <stdio.h>
#include "pr00.h"



int main_pr0(int argc, char *argv[]) {
    //clientTest1();
    //clientTest2();
    //clientTest3();
    //clientTest4(1000);
    clientTest5();
    return 0;
}

void clientTest1(){
    //Criar array uniforme com valores distintos
    //Organizar array

    int N = 20;
    int * V = newIntArray(N);
    uniformDistinctArray( V,N, 1, 50);
    printArray(V, N);
    sortIntArray(V,N);
    printArray(V, N);
}


void clientTest2(){
    int N = 1000;
    int *V = newIntArray(N);
    readInts("../data/1Kints.txt",V, 1000);
    sortIntArray(V,N);
    printArray(V, N);
}

void clientTest3(){
   int array[5] = {10, 100, 1000, 10000, 100000};
   for(int i = 0; i <5; i++){
       clientTest4( array[i]);
   }
}

void clientTest4(int N) {
    long long timeInit, timeEnd, t;
    gettimeuseconds(&timeInit);
    int *V =  newIntArray(N);
    uniformDistinctArray(V,N,1000,10000);
    sortIntArray(V,N);
    printArray(V,N);
    gettimeuseconds(& timeEnd);
    t = timeEnd- timeInit;
    printf("Tempo de execucao: %lld(us)\n",t);
}

void clientTest5(){
    int v[] = {1,2,3,4,5,6,7,8,9,10,11};
    writeIntsHeader("../data/my_file.txt", v, 11);
    int *v2,  N2=0;
    N2 = readIntsHeader("../data/my_file.txt", &v2);
    printArray(v2,N2);
}