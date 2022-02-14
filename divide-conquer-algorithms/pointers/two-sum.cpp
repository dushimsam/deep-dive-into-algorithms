#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr, int low, int high, int target, int excluded_index)
{
    int n = arr.size();
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target && mid != excluded_index)
            return mid;

        if (arr[mid] < target)
            return binary_search(arr, mid + 1, high, target, excluded_index);
        else
            return binary_search(arr, low, mid - 1, target, excluded_index);
    }
    return -1;
}

vector<int> findSums(vector<int> arr, int target)
{
    vector<int> sums;

    for (int i = 0; i < arr.size(); i++)
    {
        int check_index = target - arr[i];
        int another_id = binary_search(arr, 0, arr.size() - 1,check_index, i);
        if (another_id != -1)
        {
            sums.push_back(i + 1);
            sums.push_back(another_id + 1);
            break;
        }
    }
    return sums;
}
// O(nlog n)

int main()
{
    vector<int> nums = {2, 7, 11,15};
    int target = 9;
    vector<int> output;
    output = findSums(nums,target);

    for (int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
    return 0;
}