#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<vector<string>> vvs;

vvs groupAnagrams(vs words)
{
    unordered_map<string, vs> anagrams;

    for (int i = 0; i < words.size(); i++)
    {
        string sortedWd = words[i];
        sort(sortedWd.begin(), sortedWd.end());
        if (anagrams.find(sortedWd) != anagrams.end())
        {
            anagrams[sortedWd].push_back(words[i]);
        }
        else
        {
            anagrams[sortedWd] = vector<string>{words[i]};
        }
    }

    vvs result;
    for (auto it : anagrams)
    {
        result.push_back(it.second);
    }

    return result;
}

int main()
{

    vs words = {"yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"};
    // Expected list - [["yo","oy"], ["flop","olfp"], ["act","tac", "cat"], ["foo"]]
    vvs output = groupAnagrams(words);
    return 0;
}