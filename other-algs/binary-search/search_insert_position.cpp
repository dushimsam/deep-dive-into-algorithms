#include <bits/stdc++.h>
using namespace std;

int binary_search_insert_position(vector<int> arr, int target, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        
        if(mid != 0 && arr[mid-1] < target <= arr[mid]) return mid;

        else if (arr[mid] > target)
            return binary_search_insert_position(arr, target, low, mid - 1);
        else
            return binary_search_insert_position(arr, target, mid+1, high);
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 5, 6};
    int target = 5;
    // Expected 1
    cout << binary_search_insert_position(arr, target, 0, arr.size() - 1);
    return 0;
}