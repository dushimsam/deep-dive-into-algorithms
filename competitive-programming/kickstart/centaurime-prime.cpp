#include <iostream>
#include <string>

using namespace std;

string GetRuler(const string& kingdom)
{

     
    int len = kingdom.length();

    if (!isalpha(kingdom[len - 1]) || kingdom[len- 1] == 'Y' || kingdom[len - 1] == 'y') return "nobody";

    char vowels[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };


    for (int i = 0; i < 10; i++)
    {
        if (kingdom[len - 1] == vowels[i])
        {
            return "Alice";
            break;
        }
    }

    return "Bob";
}

int main()
{
    int testcases;
    cin >> testcases;
    string kingdom;

    for (int t = 1; t <= testcases; ++t)
    {
        cin >> kingdom;
        cout << "Case #" << t << ": " << kingdom << " is ruled by "
            << GetRuler(kingdom) << ".\n";
    }
    return 0;
}
