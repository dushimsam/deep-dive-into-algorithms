#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 
#endif

void count_minorities(string s) {
    int ones = 0;
    int zeros = 0;
    if (s.length() == 1 || s.length() == 2)
        cout << "0\n";
    else {
        for (int i = 0; i < s.length();i++) {
            if (s[i] == '0')
                zeros++;
            else
                ones++;
        }

        if (ones == zeros)
            cout << "0\n";
        else {
            if (ones < zeros)
                cout << ones<<"\n";
            else
                cout << zeros<<"\n";
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        count_minorities(s);
    }
    return 0;
}