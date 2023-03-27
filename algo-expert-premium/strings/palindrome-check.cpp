#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left <= right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{

    string str = "abcdcba";

    // expected result - true

    cout << isPalindrome(str) << endl;

    return 0;
}