#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/***
 * @author Dush Sam.
 *
 *                       QUICK SORTING ALGORITHM
 * TIME COMPLEIXTY:
 *    WORST CASE -  O(n^2)
 *    AVERAGE CASE - O(n*log(n))
 *    BEST CASE - O(n*log(n))

 * Tutorial: https://www.youtube.com/watch?v=QN9hnmAgmOc&t=17s
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

void swap(int* a,int* b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}


int partition(vi arr, int low,int high){
    int start = low;
    int end = high;
    int pivot = arr[low];

    while(start < end){
        // keep on incrementing the start index when the e[start] is less than the pivot.
        while(arr[start] < pivot){
            start++;
        }


        // keep on decrementing end index whenever e[end] is greater than pivot.
        while(arr[end] > pivot){
            end--;
        }

        if(start < end){
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[low],&arr[end]);

    return end;
}

void quickSort(vi& arr,int low,int high){
    
    // As long as the low is less than high
    if(low < high){
         int pi = partition(arr,low,high);
        // Continue partitioning at the left side of the previous pivot's index
         quickSort(arr,low,pi-1);
        // Continue partitioning at the right side of the previous pivot's index
         quickSort(arr,pi+1,high);
    }

}

void printArr(vi arr)
{
    cout << "\n";
    for (int e : arr)
        cout << e << " ";
}

int main(){

 vi arr = {64, 25, 12, 22, 11};
 quickSort(arr,0,arr.size()-1);
 printArr(arr);

    return 0;
}

