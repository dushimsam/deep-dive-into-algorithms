#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif



int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    int t, len;
    string str;
    cin >>t;
    while (t--) {
        cin>>len;
        cin>>str;
        if (str.length() == 1 || (str.length() == 2) && str[0] != str[1]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}