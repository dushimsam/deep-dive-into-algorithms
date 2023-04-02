#include <bits/stdc++.h>
using namespace std;

bool generateDocument(string characters, string document)
{
    unordered_map<char, int> mp;

    // add all given characters in the hash_map
    for (int i = 0; i < characters.length(); i++)
    {
        if (mp.find(characters[i]) != mp.end())
        {
            mp[characters[i]]++;
        }
        else
        {
            mp[characters[i]] = 1;
        }
    }
    // check if the char is present in the hashmap, if present reduce frequency, if not or frequency at that character is zero, return false.
    for (int i = 0; i < document.length(); i++)
    {
        if (mp.find(document[i]) == mp.end() || mp[document[i]] == 0)
            return false;

        mp[document[i]]--;
    }

    return true;
}

int main()
{

    string characters = "Bste!hetsi ogEAxpelrt x ";
    string document = "AlgoExpert is the Best!";

    // expected result - true
    cout << generateDocument(characters, document) << endl;

    return 0;
}