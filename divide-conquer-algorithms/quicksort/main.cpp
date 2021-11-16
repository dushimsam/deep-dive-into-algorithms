
#include<iostream>

using namespace std;

// Swapping two values.
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {
    int i = low - 1; // important thing. i points to the latest small element to the pivot one.
    int pivot = arr[high]; //let the pivot be the last element.

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            swap(arr[i + 1], arr[j]);
            i++;
        }
    }
    swap(arr[i + 1], arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quickSort(arr, low, pivot_index - 1); // PARTITIONED GROUP
        quickSort(arr, pivot_index + 1, high); // PARTITIONED GROUP
    }
}

int main() {
    int inputArray[] = {8, 4, 2, 1};
    int arrLen = sizeof(inputArray) / sizeof(inputArray[0]);

    quickSort(inputArray, 0, arrLen - 1);

    // Printing the sorted data.
    cout << "\nSorted Data ";
    for (int i = 0; i < arrLen; i++)
        cout << "->" << inputArray[i];

    return 0;
}