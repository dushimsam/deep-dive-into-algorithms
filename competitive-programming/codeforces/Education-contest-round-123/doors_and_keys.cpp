#include<bits/stdc++.h>
using namespace std;

bool isKey(char a) {
    if (a == 'r' || a == 'b' || a == 'g') return true;
    return false;
}

bool checkExists(vector<char> tracked_keys, char door) {
    for (int i = 0;i < tracked_keys.size();i++)
        if (tracked_keys[i] == tolower(door)) return true;
    return false;
}
int checkDoorKey(string s) {
    vector<char> tracked_keys;

    for (int i = 0;i < s.length();i++) {
        if (isKey(s[i]))tracked_keys.push_back(s[i]);
        else if (!checkExists(tracked_keys, s[i])) return false;
    }

    return true;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        if (checkDoorKey(s)) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    return 0;

}