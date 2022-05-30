#include<bits/stdc++.h>
using namespace std;


/***
 *      QUESTION: GIVEN AN ARRAY OF NUMBERS , FIND THE SUM BETWEEN TWO RANGE OF INDEXES.
 *      Example: Given this array , arr={1 ,3 ,4, 8, 6, 1, 4 ,2};
 *      Find the sum between index 3 and 6.
 *       
 *      APPROACH :
 *      1. Calculate the prefix sums : O(n)
 *      2. To find the sum between point a and b. take prefix_sum[b] - prefix_sum[a-1]
 * 
***/
int findMinQueries(vector<int> arr, int a, int b) {
    vector<int> prefix_sum_arr(arr.size(), arr[0]);
    //Fill the values for the prefix sums
    for (int i = 1;i < arr.size();i++)
        prefix_sum_arr[i] = arr[i] + prefix_sum_arr[i - 1];

    // Find the sum in this range (a,b)
    int sum = prefix_sum_arr[b] - prefix_sum_arr[a - 1];
    return sum;
}

int main() {
vector<int> arr={1 ,3 ,4, 8, 6, 1, 4 ,2};
 int a = 3;
 int b = 6;

cout<<findMinQueries(arr,a,b);
    return 0;
}