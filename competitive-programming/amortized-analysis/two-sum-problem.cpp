#include<bits/stdc++.h>
using namespace std;
/***
 *  PROBLEM: GIVEN THE SORTED ARRAY , find the two numbers wich sums to a given particular target.
 * APPROACH:
 * 1.   Three variables , sum = 0, left_pointer = first_element_index, right_pointer= last_element_index
 * 2.   loop -  while(left_pointer < right_pointer)
 * 3.   sum = arr[left_pointer] + array[right_pointer]
 * 4.   if (sum > target) then right_pointer-- // Means reduce the right_pointer.
 * 5.   else if(sum < target) then left_pointer++ // Add more values.
 * 6.   else return {left_pointer,right_pointer}
 ***/

vector<int> twoSumProblem(vector<int> arr, int target) {
    int left_pointer = 0;
    int right_pointer = arr.size() - 1;
    int sum = 0;

    while (left_pointer < right_pointer) {
        sum = arr[left_pointer] + arr[right_pointer];

        if (sum > target) right_pointer--;
        else if (sum < target) left_pointer++;
        else return{ arr[left_pointer],arr[right_pointer] };
    }
    return {};
}
int main() {
    vector<int> arr = { 1,4,5,6,7,9,9,10 };
    int target = 12;
    vector<int> result = twoSumProblem(arr, target);
    cout << "First number: " << result[0] << " , Second number :" << result[1];
    return 0;
}