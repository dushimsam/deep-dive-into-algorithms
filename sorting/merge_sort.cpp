#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/***
 * @author Dush Sam.
 *
 *                       MERGE SORTING
 * TIME COMPLEIXTY:
 *      WORST CASE: O(nlogn)
 *      BEST CASE: O(nlogn)
 *
 *                        APPROACH
 *
 * 1.     DIVIDE ARR INTO TWO PARTS (PARTITIONING- log(n))
 * 2.     IMPLEMENT SORTING IN O(n) WHILE MERGING.
 *
 *                        INSIGHTS
 * 1. MergeSort works on the principle that joining together the sorted subsets can be done in O(n) time.
 ***/

void merge(vi &arr, int low, int mid, int high)
{

    int n1 = mid - low + 1;
    int n2 = high - mid;

    vi LEFT(n1);
    vi RIGHT(n2);

    // Fill the elements of the left arr and the right arr
    for (int i = 0; i < n1; i++)
    {
        LEFT[i] = arr[i + low];
    }

    for (int i = 0; i < n2; i++)
    {
        RIGHT[i] = arr[i + mid + 1];
    }

    int k = low;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (LEFT[i] <= RIGHT[j])
        {
            arr[k] = LEFT[i];
            i++;
        }
        else
        {
            arr[k] = RIGHT[j];
            j++;
        }
        k++;
    }

    // the possible left elements in the LEFT SUB ARR
    while (i < n1)
    {
        arr[k] = LEFT[i];
        i++;
        k++;
    }

    // the possible left elements in the RIGHT SUB ARR
    while (j < n2)
    {
        arr[k] = RIGHT[j];
        j++;
        k++;
    }
}

void mergeSort(vi &arr, int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        cout<<mid<<endl;
        // Partition the elements on the left
        mergeSort(arr, low, mid);
        // Continue partitioning the elemets on the right
        mergeSort(arr, mid + 1, high);

        // merge the two partitioned parts
    
        merge(arr, low, mid, high);
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
    vi arr = {12, 10, 9, 5, 1};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);
    printArr(arr);

    return 0;
}