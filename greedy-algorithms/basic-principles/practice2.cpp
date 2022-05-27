#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


void merge(vi &par_arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vi arr1(n1);
    vi arr2(n2);

    for (int i = 0;i < n1;i++) {
        arr1[i] = par_arr[low + i];
    }
    for (int i = 0;i < n2;i++) {
        arr2[i] = par_arr[mid + 1 + i];
    }

    // for the arr1
    int i = 0;

    //for the arr2
    int j = 0;

    // indexing the position of the next element in the parent arr
    int k = low;

    while (i < arr1.size() && j < arr2.size()) {

        if (arr1[i] < arr2[j]) {
            par_arr[k] = arr1[i];
            i++;
        }
        else {
            par_arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < arr1.size()) {
        par_arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < arr2.size()) {
        par_arr[k] = arr2[j];
        j++;
        k++;
    }
}


void mergeSort(vi &arr, int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {

    vi arr = { 6,5,12,10,9,1 };

    mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0;i < arr.size();i++)cout << arr[i] << " ";

    return 0;
}