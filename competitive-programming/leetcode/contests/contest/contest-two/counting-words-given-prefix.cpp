#include <bits/stdc++.h>
using namespace std;
int checkcontains(string pref, string word)
{
    for (int i = 0; i < pref.length(); i++)
    {
        if (pref[i] != word[i])
            return false;
    }
    return true;
}
int countPrefix(string pref, vector<string> words)
{
    int count = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (checkcontains(pref, words[i]))
            count++;
    }
    return count;
}

int main()
{

    return 0;
}