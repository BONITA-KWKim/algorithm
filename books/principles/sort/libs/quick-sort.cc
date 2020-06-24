#include "quick-sort.h"

void QuickSort::sort (int *arr, int st, int sp) {
    if (st >= sp) return;

    int pivot_idx = 0;

    pivot_idx = partition(arr, st, sp);

    sort(arr, st, pivot_idx-1);
    sort(arr, pivot_idx, sp);
}

void QuickSort::swap (int *arr, int i, int j) {
    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
}

int QuickSort::partition (int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[j];

    while (i < j) {
        while (arr[i] < pivot) {
            ++i;
        }

        while (i < j && arr[j] >= pivot) {
            --j;
        }

        swap(arr, i, j);
    }

    arr[right] = arr[j];
    arr[j] = pivot;

    return j;
}