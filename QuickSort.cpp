#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list) {
    quickSort(list, 0, list.size()-1);
    return list;
}

void QuickSort::quickSort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<int>& list, int low, int high) {
    int pivotIndex = low + 2; // Third value as pivot
    int pivot = list[pivotIndex];
    std::swap(list[pivotIndex], list[high]); // Move pivot to end
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);
    return (i + 1);
}
