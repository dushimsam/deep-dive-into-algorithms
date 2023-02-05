#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    int global_diff = INT_MAX;
    vector<int> res(2, 0);

    for (int i = 0; i < arrayOne.size(); i++)
    {
        int diff = INT_MAX;
        int num;

        for (int j = 0; j < arrayTwo.size(); j++)
        {
            int curr_diff = abs(arrayOne[i] - arrayTwo[j]);
            if (curr_diff < diff)
            {
                diff = curr_diff;
                num = arrayTwo[j];
            }
            else
            {
                break;
            }
        }
        if (diff < global_diff)
        {
            res[0] = arrayOne[i];
            res[1] = num;
            global_diff = diff;
        }
    }
    return res;
}

int main()
{
    vector<int> arr1 = {10, 0, 20, 25, 2200};
    vector<int> arr2 = {1005, 1006, 1014, 1032, 1031};

    vector<int> res = smallestDifference(arr1, arr2);

    cout << res[0] << " " << res[1] << " " << endl;

    return 0;
}