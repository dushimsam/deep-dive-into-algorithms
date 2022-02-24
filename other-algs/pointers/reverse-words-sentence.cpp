#include <bits/stdc++.h>

using namespace std;

void reverseSentence(string s)
{
    string new_sentence = "";
    string full_word;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        full_word.push_back(s[i]);

        if (isspace(s[i]) || i == 0)
        {
            full_word.erase(remove(full_word.begin(), full_word.end(), ' '), full_word.end());

            if (new_sentence.size() == 0)
            {
                new_sentence = full_word;
            }
            else
            {
                new_sentence = full_word + " " + new_sentence;
            }
            full_word = "";
        }
    }

    cout<<new_sentence<<endl;
}

int main()
{
    reverseSentence("God Ding");
    return 0;
}