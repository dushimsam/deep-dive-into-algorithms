
#include<bits/stdc++.h>
using namespace std;

/**
 *                           ALGORITHM
 *  1. Every k , the array returns to how it started. Let k  %= n;
 *  2. Copy the Elements From (n-k) to n into the empty new array.
 *  3. Append the Elements from 0 to (n-k) to the new array.
 */
// Function to rightRotate array
void rotateArr(vector<int> arr,  int k)
{
  int n = arr.size();
  k %= n; // Because we know at every k rotation it returns to the array we started with.
  vector<int> result; 

  // Let the last (n-k) elements be the first into the new array ("result")

  for(int i = (n - k); i <n; i++){
      result.push_back(arr[i]);
  }

  // Copy the first k elements at the end of the new array.

  for(int i = 0; i <(n - k); i++){
      result.push_back(arr[i]);
  }

  // Print the new array

  for(int i =0;i<n;i++)
     cout<<result[i]<<" ";
}
	
// Driver code

// TIME COMPLEXITY O(n);
int main()
{
	vector<int> nums = {1,2,3,4,5,6,7};
    int  k = 3;
	rotateArr(nums,k);

    return 0;
}