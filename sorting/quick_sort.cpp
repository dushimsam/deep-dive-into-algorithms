#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/***
 * @author Dush Sam.
 *
 *                       QUICK SORTING ALGORITHM
 * TIME COMPLEIXTY:
 * 
 *    WORST CASE -  O(n^2)
 *    AVERAGE CASE - O(n*log(n))
 *    BEST CASE - O(n*log(n))

 * Tutorial: https://www.javatpoint.com/quick-sort
 *
 *                        PRINCIPLE OF THE ALGORITHM
 *
 * Predicting onwards the appropriate position of the element in the sorted array.
 *
 *                        APPROACH
 *    IF (LOW < HIGH)
 *           LOCATION = PARTITION(ARR,LOW,HIGH)
 *           QUICK_SORT(ARR,LOW,LOCATION-1)
 *           QUICK_SORT(ARR,LOCATION+1,HIGH)
***/

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vi &arr, int start, int end)
{
    int i = start - 1;
    int pivot = arr[end];

    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(vi &arr, int low, int high)
{

    // As long as the low is less than high
    if (low < high)
    {
        int pi = partition(arr, low, high);
        // Continue partitioning at the left side of the previous pivot's index
        quickSort(arr, low, pi - 1);
        // Continue partitioning at the right side of the previous pivot's index
        quickSort(arr, pi + 1, high);
    }
}

void printArr(vi arr)
{
    cout << "\n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

int main()
{

    vi arr = {9, 25, 22, 12, 11, 1, -100};
    int n = arr.size();

    quickSort(arr, 0, n - 1);
    printArr(arr);

    return 0;
}
