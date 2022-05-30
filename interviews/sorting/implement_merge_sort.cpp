#include <bits/stdc++.h>
using namespace std;

// NOT WORKING .................
// visit link: https://www.programiz.com/dsa/merge-sort

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    // fill in the values from our array.
    //  add the left elements

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i]; // Meaning you should start from that.
    }

    // add the right elements
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[r + i + 1]; // since we added 1 on the m when calling the mergeSort on the right side before.
    }

    int j, i = 0;
    int k = l;

    // Merge the two subarrays with respect to their values.

    while (j < n1 && i < n2)
    {
        if (L[j] <= R[i])
        {
            arr[k] = L[j];
            j++; // continue to the next element.
        }
        else
        {
            arr[k] = R[i];
            i++; // continue to the next element.
        }
        k++;
    }

    //  Copy the left elements if there is  remaining

    while (j < n1)
    {
        arr[k] = L[j];
        j++;
        k++;
    }

    //  Copy the right elements if they is any  remaining

    while (i < n2)
    {
        arr[k] = R[i];
        i++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        //find the middle index
        int m = l + (r - l) / 2;

        // m should replace one of the two in the each of the foll. lines.
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    printArray(arr, size);
    return 0;
}