#include<bits/stdc++.h>
using namespace std;


vector<string> simplifyFractions(int n) {
    vector<string> res;

    for (int i = 1;i < n;i++) {
        for (int j = (i + 1);j <= n;j++) {
            if (gcd(i, j) == 1)
                res.push_back(to_string(i) + "/" + to_string(j));
        }
    }

    return res;
}
int main() {
    vector<string> res = simplifyFractions(2);
    for (string e : res) {
        cout << e << endl;
    }
    return 0;
}