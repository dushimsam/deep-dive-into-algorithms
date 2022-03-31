#include<bits/stdc++.h>
using namespace std;

/***
 *                            QUESTION
 * 
Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 * 
 *                            INSIGHTS
 * 
 * 1. We shall use the same algorithm for LIS but add a little bit of stuffs. such as count[] arr
 *    which is in charge of indicating the # of increasing subsequences which ends at a particular index.
 * 2. the dp[] arr , is in charge of indicating the # of elements in an increasing subsequence which ends at a particular index.
 *                         
 *                     Important techniques used.
 *   !!! They both apply if the current element is greater than a particular prev element (nums[i] > nums[j])
 * 
 *  i. Sequence Extending (dp[i] == dp[j]):  whenever the prev and the current element , share the same dp value then the count of that prev element should be the same count for that curr elem. Eg: count[i] = count[j];
 *     Meaning that we are extending our sequence.
 *     After words we are going to increase the dp[i] by  1 , since we have added one new element in the sequence.
 * 
 *  ii. Incrementing the path (dp[i] == dp[j] + 1) : When the ever the previous element is far less than curr element on dp value by 1. We just increment  the count.
 *      Meaning that we found a new path.
 * 
 *                            APPROACH
 * count[n] , dp[n] , fill(count,dp,1);
 * int maxEl;
 * 
 * for(int i=0;i<n;i++)
 *    for(int j= 0; j<i;j++)
 *         if(arr[i] > arr[j])
 *            if(dp[i] == dp[j]) 
 *                   count[i] = count[j]
 *                   dp[i] +=1;
 *            else if(dp[i] == dp[j]+1)
 *                    count[i] += count[j]  
 *     maxEl = max(maxEl,dp[i])
 * int ans = 0; 
 * for(int i=0;i<n;i++) if(dp[i] == max) ans += count[i]
 * 
 * return ans
***/
int findLongestIncreasingSubsequencesCount(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> count(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            // if()
        }
    }
}

int main(){


    return 0;
}