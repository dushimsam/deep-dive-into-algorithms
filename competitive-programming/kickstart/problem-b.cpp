#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    bool isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    // evaluates to 1 (true) if c is an uppercase vowel
   bool isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string input_text;
        cin >> input_text;

        char last_char = input_text[input_text.length() - 1];

        cout << "Case #" << i << ": ";
        if (isalpha(last_char) && last_char != 'Y' && last_char != 'y')
        {
            cout << "Bob";
        }
        else if(isVowel(last_char))
        {
            cout << "Alice";
        }
        cout << endl;
    }
    return 0;
}