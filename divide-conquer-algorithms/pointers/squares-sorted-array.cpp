#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------------
                      ALGORITHM

1. Declare the right = n-1 and the left =0 incrementer , new array "result[]" to keep track of the sorted squuared version.
2. Make a decrementor ; "index" starting from n-1 to zero.
2. Check if abs(left) > abs(right) then replace the current_index to the value (arr[left]^2).
3. Else replace the current_index to the value (arr[right]^2)
4. That's all.

*/
void squares_sorted_array(vector<int> &arr)
{
    int result[arr.size()];
    int right = arr.size() - 1;
    int left = 0;

    for (int current_index = arr.size() - 1; current_index >= 0; current_index--)
    {
        if (abs(arr[left]) > arr[right])
        {
            result[current_index] = arr[left] * arr[left];
            left++;
        }
        else
        {
            result[current_index] = arr[right] * arr[right];
            right--;
        }
    }

    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << "\n"
             << result[i];
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(-6);
    arr.push_back(-3);
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(5);
    squares_sorted_array(arr);
    return 0;
}