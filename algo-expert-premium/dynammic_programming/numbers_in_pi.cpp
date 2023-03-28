#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<int, int> mp;

int getMinSpaces(string pi, set<string> numbersTable, mp &cache, int idx)
{
    // return -1 if the number on which we called this fn was the last one
    if (idx == pi.length())
        return -1;
    // check if the value for this particular idx already exists in the cache, so that we don't make unnecessary repetition
    if (cache.find(idx) != cache.end())
        return cache.at(idx);
    // declare the minSpaces variable for this particular idx
    int minSpaces = INT_MAX;
    // iterate from this current idx to the end, trying to minimize the space
    for (int i = idx; i < pi.length(); i++)
    {
        // create a prefix - from this idx back to the end
        string prefix = pi.substr(idx, i + 1 - idx);
        // check if the prefix exists in the set 'numbersTable'
        if (numbersTable.find(prefix) != numbersTable.end())
        {
            // reduce the existing spaces
            int minSpacesInSuffix = getMinSpaces(pi, numbersTable, cache, i + 1);

            // Handle int overflow
            if (minSpacesInSuffix == INT_MAX)
            {
                minSpaces = min(minSpacesInSuffix, minSpaces);
            }
            else
            {
                minSpaces = min(minSpaces, minSpacesInSuffix + 1);
            }
        }
    }
    // insert the min spaces for this idx
    cache.insert({idx, minSpaces});
    // return the min spaces for the idx
    return cache.at(idx);
}

int numbersInPi(string pi, vector<string> numbers)
{
    // create the set to store the numberse
    set<string> numbersTable;
    // insert numbers in the set
    for (string num : numbers)
    {
        numbersTable.insert(num);
    }
    mp cache;
    // lead numbers from the back to the front
    for (int i = pi.length() - 1; i >= 0; i--)
    {
        // for each number fill up the minSpaces for it. by Calling getMinSpaces function
        getMinSpaces(pi, numbersTable, cache, i);
    }
    // return the minSpaces from the cache located at 0' index
    return cache.at(0) == INT_MAX ? -1 : cache.at(0);
}

int main()
{

    string pi = "3141592653589793238462643383279";
    vector<string> nums = {"314159265358979323846", "26433", "8", "3279", "314159265", "35897932384626433832", "79"};
    // Expected result - 2
    cout << numbersInPi(pi, nums) << endl;
    return 0;
}