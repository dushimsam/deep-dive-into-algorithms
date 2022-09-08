#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void merge(vi &arr, int low, int mid, int high) {
    int n1 = (mid - low) + 1;
    int n2 = (high - mid);

    vi arr1(n1);
    vi arr2(n2);

    for (int i = 0;i < n1;i++) {
        arr1[i] = arr[low + i];
    }

    for (int i = 0;i < n2;i++) {
        arr2[i] = arr[mid + i + 1];
    }

    int k = low;
    int i = 0;
    int j = 0;

     while (i < arr1.size() && j < arr2.size()) {

        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < arr1.size()) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < arr2.size()) {
        arr[k] = arr2[j];
        j++;
        k++;
    }

}
void mergeSort(vi &arr, int low, int high) {

    if (low < high) {
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

    }

}


int main() {

    vi arr = { 6,5,12,10,9,1 };
    mergeSort(arr,0,arr.size()-1);
    
    for(int e:arr)cout<< e << " ";

    return 0;
}