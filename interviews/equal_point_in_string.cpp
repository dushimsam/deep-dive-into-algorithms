#include <bits/stdc++.h>
using namespace std;

int countClosingBrackets(string s)
{
    char c = ')';
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
            count++;
    }

    return count;
}
int findEqualPoint(string s)
{
    int closingBrackets = countClosingBrackets(s);
    int openingBrackets = 0;
    char o = '(';

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == o)
            openingBrackets++;
        else
            closingBrackets--;

        if (openingBrackets == closingBrackets)
            return i;
    }
    return 0;
}

int main()
{
    string str = "))";
    cout << findEqualPoint(str)+1;
    return 0;
}