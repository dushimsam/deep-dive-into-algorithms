#include<bits/stdc++.h>
using namespace std;

/***
 *
we are given an array of n positive
integers and a target sum x,
and we want to find a subarray whose sum is x
 *
 *            APPROACH (https://www.youtube.com/watch?v=Ofl4KgFhLsM)
 *
 * 1. Create 3 variables. left_pointer = 0 ; right_pointer = 0 ; sum = 0;
 * 2. Create a loop from 0 until array.length(); (right_pointer = 0 until n)
 * 3. If(sum > target && start < array.length()-1){ sum -= array[left_pointer]; left_pointer++; }
 * 4. If(sum == k) return true;
 * 5. sum =+ sum[right_pointer];
 * 6. right_pointer++;
 * ***/

vector<int> findSubarray(vector<int> arr, int target) {
    int sum = arr[0];
    int left_pointer = 0;
    int right_pointer = 1;

    while (right_pointer < arr.size()) {

        while (sum > target && left_pointer < right_pointer) {
            sum -= arr[left_pointer];
            left_pointer++;
        }
        if (sum == target) {
            return { left_pointer , right_pointer-1 };
        }
        
        sum += arr[right_pointer];
        right_pointer++;
    }
    return {};
}

int main() {
    vector<int> arr = {10,2,4,7,5};
    int sum = 13;

    vector<int> result = findSubarray(arr, sum);

    cout<<"Range "<<result[0]<<" , "<<result[1];
    return 0;
}