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
1. Create a dp array (dp_arr) keeping in track of the longest subsequence at a particular index.
2.
     for(i = 0 until n)
        // Go through all the elements of the array below the current k'th index

        dp_arr[k] = 1;

        for(k = 0 until i)

           //
           if(elements[i] < elements[k]) ->  dp_arr[k] = max(dp_arr[k],1 + dp_arr[i])

*/
int longestIncreasingSubsequence(vector<int> elements)
{
    int cols = elements.size();
    vector<int> dp_arr(cols, 1);

    for (int i = 1; i < cols; i++)
    {
        for(int k = 0 ; k < i;k++){
            if(elements[i] > elements[k]){
                dp_arr[i] = max(dp_arr[i], 1 + dp_arr[k]);
            }
        }
    }
    return dp_arr[cols-1];
}

int main()
{

vector<int> arr= {2,5,6,1,7};
cout<<longestIncreasingSubsequence(arr);
    return 0;
}