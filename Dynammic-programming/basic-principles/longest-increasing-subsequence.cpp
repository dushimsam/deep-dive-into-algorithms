#include <bits/stdc++.h>
using namespace std;

/*
                    PROBLEM:
GIVEN [2,5,6,1,7]
QUESTION : Find the longest increasing subsequence.
SOLUTION: - [2,5,6,7] - 4 elements
POssible increasing subsequences : {2}, {5},{6},{1},{7} , {2,5},{2,5,6},{5,6},{1,7}...

Approach:
We are going to find the solution from the arr of len - 0 to len - n

STEPS:
1. Create a dp array (dp_arr) , fill(dp_arr,1) keeping in track of the longest subsequence at a particular index.
2.
     let maxElem = 0;

     for(i = 0 until n)
        // Go through all the elements of the array below the current k'th index
        for(k = 0 until i)
           //search in all the prev. elements less than the current.
           // and find the element which gives the largest 
           if(elements[i] == elements[k]) ->  dp_arr[i] += 1
        
        maxElem = max(maxElem,elements[i])

*/

int lengthOfLIS(vector<int> &nums)
{
    int maxElem = 0;
    int n = nums.size();

    if (n <= 1)
        return 1;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[i] == dp[j])
                    dp[i] += 1;
            }
        }
        maxElem = max(maxElem, dp[i]);
    }
    return maxElem;
}


int main()
{


vector<int> arr= {6, 2, 5, 1, 7, 4, 8, 3};
cout<<lengthOfLIS(arr);
    return 0;
}