#include <stdio.h>
#include "selecao.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int v[], int left, int right) {
    int pivot = v[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (v[j] <= pivot) {
            swap(&v[i], &v[j]);
            i++;
        }
    }

    swap(&v[i], &v[right]);
    return i;
}

// Busca linear
int linear_search(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++) {
        if (v[i] == alvo) {
            return i; // encontrou
        }
    }
    return -1; // não encontrou
}

// Quick Select (k-ésimo menor)
int quick_select(int v[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(v, left, right);

        if (pivotIndex == k) {
            return v[pivotIndex];
        } else if (pivotIndex > k) {
            return quick_select(v, left, pivotIndex - 1, k);
        } else {
            return quick_select(v, pivotIndex + 1, right, k);
        }
    }
}