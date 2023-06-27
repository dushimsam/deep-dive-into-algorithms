#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout << 0 << endl;
    for(int i = 2; i <= n; i++){
       int res = ((i * i) * ((i * i) - 1)) / 2 - (4 * (i - 2) * (i - 1));
       cout << res << endl;
    }
    return 0;
}