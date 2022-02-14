#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr,int x,int low ,int high){
     if(high >= low){
         // Look for the middle element's index.

        int mid = low+(high-low)/2;
        if(arr[mid] == x)
            return mid;
        
        // Recur on the right of the subarray if element at mid is less than the X.
         if(arr[mid] < x) { 
            return binary_search(arr,x,mid+1,high);
        }

          // Recur on the left of the subarray if element at mid is greater than the X.
          // Means high should be that less than mid by one distance.
         if(arr[mid] > x) { 
            return binary_search(arr,x,low,mid-1);
        }

     }

     return -1;
}
int main(){


    return 0;
}