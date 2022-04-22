#include <bits/stdc++.h>
using namespace std;


/*** source :->
 *
 *  https://cp-algorithms.com/string/string-hashing.html
 *
 *
 ***/
long long computer_hash(string str)
{
    const int increase = 31;
    const int m = 1e9 + 9;

    long long hash_value = 0;
    long long p = 1;

    for (int i = 0; i < str.length(); i++)
    {
        int dist = str[i] - 'a' + 1;
        hash_value = (hash_value + (p * dist)) % m;
        p = (p * increase) % m;
    }

    return hash_value;
}
int main()
{
    string str = "coding";
    cout << computer_hash(str);
    return 0;
}