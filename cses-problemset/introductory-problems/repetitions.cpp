#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    if (str.length() == 0)
        cout << 0 << endl;
    else
    {
        char prev = str[0];
        int count = 1;
        int maxCount = 1;

        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == prev)
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else
            {
                count = 1;
            }
            prev = str[i];
        }
        cout << maxCount << endl;
    }
    return 0;
}