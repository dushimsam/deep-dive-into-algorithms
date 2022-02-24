#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string sentence)
{
    vector<string> arr;
    


     if(sentence.length() == 0)  return 0;
     else if(sentence.length() == 1) return 1;
     
    string word;
    for (int i = 0; i < sentence.length(); i++)
    {
        size_t found = word.find(sentence[i]);

        if (found != string::npos)
        {
            arr.push_back(word);
            word = "";
            word.push_back(sentence[i]);
        }
        else
        {
            word.push_back(sentence[i]);
        }
    }

    int max = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].length() > max)
        {
            max = arr[i].length();
        }
    }
    return max;
}

int main()
{
    cout << longestSubstring(" ");
    return 0;
}