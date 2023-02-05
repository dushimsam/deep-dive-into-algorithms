#include<iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/****
 *   QUESTION: Find two numbers in the array that sums to the target value.
 *
 * ***/

/***
 *
 * METHOD ONE : using Two pointers method

Complexity: nlogn

***/

vector<int> twoNumberSum(vector<int> arr, int targetSum)
{
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == targetSum)
            return {arr[left], arr[right]};
        else if (sum < targetSum)
            left++;
        else
            right--;
    }

    return {};
}

/***
 *
 * METHOD TWO : USING OF SET<>
 * In this approach we just keep the current number whose it's difference with the target is not found in the set.
 * If we find that the difference exists in the set then we return the two numbers.
Complexity: O(n);

This approach is the best solution when the given array is not sorted.
***/

vector<int> twoNumberSum2(vector<int> arr, int targetSum)
{
    set<int> distinctElems;

    for (int i = 0; i < arr.size(); i++)
    {
        int diff = targetSum - arr[i];
        auto it = distinctElems.find(diff);
        if (it == distinctElems.end())
        {
            distinctElems.insert(arr[i]);
        }
        else
        {
            return {arr[i], diff};
        }
    }

    return {};
}
int main()
{
   vector<int> arr=  {3, 5, -4, 8, 11, 1, -1, 6};
   int targetSum = 10;
   
   for(int e:twoNumberSum2(arr,targetSum)){
        cout <<e << " ";
   }
    return 0;
}