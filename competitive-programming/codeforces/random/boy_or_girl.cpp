#include<bits/stdc++.h>
using namespace std;


int main() {
    string input;
    cin >> input;
    set<char> unique;
    for (int i = 0; i < input.size(); i++)unique.insert(input[i]);

    if (unique.size() % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";

    return 0;
}