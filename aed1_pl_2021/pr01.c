#include "pr01.h"

int main_pr01(int argc, char *argv[]) {
    clientTest11();
    return 0;
}

int threesumBruteForce(int a[], int N, long long *cost) {

    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++) {
                *cost = *cost + 1;
                if (a[1] + a[j] + a[k] == 0)
                    count++;
            }
    return count;
}

void clientTest10() {
    int N = 6;
    long long cost = 0;
    int v[] = {500, 1000, 2000, 4000, 8000, 16000};
    for (int i = 0; i < N; i++) {
        int *v1 = newIntArray(v[i]);
        uniformDistinctArray(v1, v[i], -v[i], v[i]);
        threesumBruteForce(v1, v[i], &cost);
        printf("%lld\n", cost);
    }
    // ciclo 0 a N
    // gerar array aleatorio de i posicoes
    // chamar threesumBruteForce
}

int bruteforceSearch(int *v, int n, long *cost, int key) {
    for (int i = 0; i < n; i++) {
        *cost = *cost + 1;
        if (v[i] == key)
            return i;
    }


}

int binarySearch1(int a[], int n, int key, long *cost) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        *cost = *cost + 1;
        int mid = (lo + hi) / 2;
        if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

void clientTest11() {
    //gerar 10k numeros random
    int *v = newIntArray(10000);
    uniformDistinctArray(v, 10000, 0, 20000);


    long cost_bf = 0, cost_bs = 0;

    //bruteforceSearch(v, 10000, &cost_bf, -100);
    binarySearch1(v, 10000, -100, &cost_bs);

    //printf("Cost Bruteforce = %ld\nCost Binary Search = %ld\n", cost_bf, cost_bs);
    printf("Cost Binary Search = %ld\n", cost_bs);

}