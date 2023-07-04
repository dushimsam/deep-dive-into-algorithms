#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<string> grayCode = {""};

    for (int i = 1; i <= n; i++)
    {
        int currSize = grayCode.size();
        // add the elements in the reverse oder
        for (int j = currSize - 1; j >= 0; j--)
        {
            grayCode.push_back(grayCode[j]);
        }

        currSize *= 2;
        // fill the first half with zeros and the second half with 1's
        for (int j = 0; j < currSize; j++)
        {
            if (j < currSize / 2)
            {
                grayCode[j] += "0";
            }
            else
            {
                grayCode[j] += "1";
            }
        }
    }

    for (string str : grayCode)
    {
        cout << str << endl;
    }
    return 0;
}