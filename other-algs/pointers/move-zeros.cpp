#include <bits/stdc++.h>
using namespace std;

/**
 *                         QUESTION
 *
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 *
 */

void moveZeroes(vector<int> &nums)
{

    for (int i = (nums.size() - 1); i >= 0; i--)
    {
        if (nums[i] == 0)
        {
            nums.erase(nums.begin() + i);
            nums.push_back(0);
        }
    }
    
    for(int i=0;i<nums.size();i++)
       cout<<nums[i]<<" ";
}

int main()
{
 
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    return 0;
}