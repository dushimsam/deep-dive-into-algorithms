#include <bits/stdc++.h>
using namespace std;

vector<string> generateCombination(string str)
{
    int n = str.size();
    vector<string> res;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        list<char> currStrL;

        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                currStrL.push_front(str[j]);
            }
        }

        string currStr;

        list<char>::iterator it;

        for (it = currStrL.begin(); it != currStrL.end(); it++)
            currStr.push_back(*it);

        res.push_back(currStr);
    }

    return res;
}

int main()
{
    vector<string> res = generateCombination("ABC");

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}