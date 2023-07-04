#include <bits/stdc++.h>
using namespace std;

int main()
{
    int freq[26], N;
    string str;
    cin >> str;
    unordered_map<char, int> mp;
    for (char ch : str)
    {
        mp[ch]++;
    }

    // count the odds
    int oddCount = 0;
    char oddChar;
    for (auto e : mp)
    {
        if (e.second % 2 != 0)
        {
            oddCount++;
            oddChar = e.first;
        }
    }

    if (oddCount > 1)
    {
        cout << "NO SOLUTION\n";
    }

    // initialize the first even part
    string half;
    for (auto e : mp)
    {
        for(int i = 1; i <= e.second/2; i++)
          half += e.first;
    }
    
    // add the odd character in the middle
    string res = half;
    if (oddCount == 1)
    {
        res += oddChar;
    }

    // reverse the first apart to append it in making the total string
    reverse(half.begin(), half.end());
    res += half;

    cout << res << endl;
    return 0;
}