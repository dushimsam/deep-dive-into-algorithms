#include <bits/stdc++.h>
using namespace std;

/**
                    ALGORITHM

1. Make one variable called 'start' to track the elements from the front.
2. Make other variable called 'end' to track the elements from the back.
3. If the addition of those are less than the target , it means that we should increment
the start.
4. Else if it is greater than the start , it means we should decrement the 'end'
5. Until the summation of the both are equal to the target.
**/

vector<int> getElements(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    vector<int> sums;
    while (end >= start)
    {
        if ((arr[start] + arr[end]) < target)
            start++;
        else if ((arr[start] + arr[end]) > target)
            end--;
        else
        {
            sums.push_back(start+1);
            sums.push_back(end+1);
            break;
        }
    }
    return sums;
}
int main()
{
  vector<int> numbers = {2,7,11,15};
  int target = 9;

  vector<int> sums = getElements(numbers,target);

  for (int i = 0; i < sums.size(); i++) cout << sums[i] << endl;

    return 0;
}