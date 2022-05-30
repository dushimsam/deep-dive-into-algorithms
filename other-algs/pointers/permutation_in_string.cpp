#include <bits/stdc++.h>
using namespace std;

bool includes_in_string(string given_string, string check_string)
{
    for (int i = 0; i < given_string.length(); i++)
    {
        if (given_string[i] == check_string[0])
        {
            int i_counter = i + 1;
            int len = 1;

            while (len < check_string.length())
            {
                if (check_string[len] != given_string[i_counter])
                    break;
                i_counter++;
                len++;
            }

            if(len == check_string.length()) return true;
        }
    }
    return false;
}

bool contains_permutation(string given_string, string check_string)
{
    do
    {
        if (includes_in_string(given_string, check_string))
            return true;
    } while (next_permutation(check_string.begin(), check_string.end()));
    return false;
}

int main()
{

   string s1 = "abcdxabcde", s2 = "abcdeabcdx";
   cout<<contains_permutation(s2,s1);
   return 0;
}