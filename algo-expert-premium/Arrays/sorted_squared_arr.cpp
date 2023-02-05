#include <iostream>
#include <vector>
using namespace std;

/***
 *  QUESTION: Given a sorted array of numbers (negative or positive)
 *  return another sorted array of the same squared numbers.
 * 
 * 
***/

vector<int> sortedSquaredArray(vector<int> array)
{
    int left = 0;
    int right = array.size() - 1;
    int currI = array.size() - 1;

    vector<int> res(array.size(), 0);

    while (left <= right)
    {
        if (abs(array[left]) > abs(array[right]))
        {
            res[currI--] = array[left] * array[left];
            left++;
        }
        else
        {
            res[currI--] = array[right] * array[right];
            right--;
        }
    }

    return res;
}

int main()
{

    vector<int> arr = {1, 2, 3, 5, 6, 8, 9};
    for (int e : sortedSquaredArray(arr))
        cout << " " << e << endl;
    return 0;
}