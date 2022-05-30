#include<bits/stdc++.h>
using namespace std;

bool compareTwoChars(string a, string b) {
    if (((a[0] == b[0]) || (a[1] == b[1])) && a != b) return true;
    return 0;
}

int letterStrings(vector<string> strs) {
    int count = 0;
    for (int i = 0;i < strs.size();i++) {
        for (int j = i + 1;j < strs.size();j++) {
            if (compareTwoChars(strs[i], strs[j])) count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int len;
        cin >> len;
        vector<string> strs;
        while (len--) {
            string str;
            cin >> str;
            strs.push_back(str);
        }
        cout << letterStrings(strs) << endl;
    }
    return 0;
}