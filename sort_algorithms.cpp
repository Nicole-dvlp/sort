#include "sort_algorithms.h"
#include <algorithm>
using namespace std;

// Сортировка методом пузырька
void bubbleSort(vector<string>& arr) {
    int n = arr.size();
    int flag = 0;
    for (int i = 0; i < n - 1; ++i) {
        flag = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) { break; }
    }
}

// Сортировка методом вставки
void insertionSort(vector<string>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Сортировка методом выбора
void selectionSort(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Быстрая сортировка
void quickSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        string pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        int partitionIndex = i + 1;

        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}