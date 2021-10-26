#include <iostream>

using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
    // why mid ??? - It is going to help us know where we the right sub-array starts from.

    //1 Step : initialization of variables

    int inversion_counts = 0;
    int i = left; // To represent the starting index of the left sub-array.
    int j = mid; // To represent the starting index of the right sub-array.
    int k = left; // To keep track with the current index in the resultant merged array.

    while ((i <= (mid - 1)) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++]; // The element at index k++ of temp array will be equal to the element at index i , then incremenet i later.
        } else {
            temp[k++] = arr[j++];
            //Since the left hand side is greater than the right one , add on the inversion count value equal to ( mid - 1).
            inversion_counts = inversion_counts + (mid - i);
        }
    }

    // Since in the above loop we used the & operation , one of the two sub-arrays might now have been visited.

    // Copy the remaining elements in the left sub-array into the array.

    while ((i <= (mid - 1)))
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Recopy the elements in the original array

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inversion_counts;
}

int _mergeSort(int arr[], int temp[], int left, int right) {
    int inversion_counts = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        // SINGLE LEFT SIDE - GET the result that belongs to all small arrays that belong to the left parent
        inversion_counts += _mergeSort(arr, temp, left, mid);

        // SINGLE RIGHT SIDE - GET the result that belongs to all small arrays that belong to the right parent
        inversion_counts += _mergeSort(arr, temp, mid + 1, right);

        // MERGE THE TWO PARENT ARRAYS INTO ONE
        inversion_counts += merge(arr, temp, left, mid + 1, right);
    }
    return inversion_counts;
}

int mergeSort(int arr[], int size) {
    int temp[4];
    int inv_counts = _mergeSort(arr, temp, 0, 3);
    return inv_counts;
}

int main() {
    int inputArray[] = {8, 4, 2, 1};
    int arrLen = sizeof(inputArray) / sizeof(inputArray[0]);
    cout << "Inversion counts " << mergeSort(inputArray, arrLen);
    cout << "\nSorted array " << "\n";
    for (int i = 0; i < arrLen; i++)
        cout << inputArray[i];
    return 0;
}
