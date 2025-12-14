#include "Sorting.h"

void bubbleSortByPH(WaterTest tests[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tests[j].pH > tests[j + 1].pH) {
                WaterTest temp = tests[j];
                tests[j] = tests[j + 1];
                tests[j + 1] = temp;
            }
        }
    }
}

int linearSearch(WaterTest tests[], int count, int id) {
    for (int i = 0; i < count; i++)
        if (tests[i].id == id) return i;
    return -1;
}

int binarySearch(WaterTest tests[], int count, int id) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (tests[mid].id == id) return mid;
        else if (tests[mid].id < id) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
