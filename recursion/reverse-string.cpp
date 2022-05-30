#include<bits/stdc++.h>
using namespace std;

vector<string> reverseString(vector<string> characters, int low, int high) {

    if (high > low) {
        string temp = characters[low];
        characters[low] = characters[high];
        characters[high] = temp;
        return reverseString(characters, low + 1, high - 1);
    }
    return characters;
}


int main() {
    vector<string> s = { "h","e","l","l","o"};
    s = reverseString(s,0,s.size()-1);

    for (int i = 0;i < s.size();i++) {
         cout<<s[i]<<endl;
    }

    return 0;
}