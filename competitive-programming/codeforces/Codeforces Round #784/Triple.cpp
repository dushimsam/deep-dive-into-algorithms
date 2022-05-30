#include<bits/stdc++.h>
using namespace std;



int main() {

    int n;
    cin >> n;
   

    while (n--) {
         map<int, int> mp;
        int len;
        cin >> len;
        int maxE = -1;
        int maxV = 0;

        while (len--) {
            int num;
            cin >> num;
            if (mp[num] == 0) mp[num] = 1;
            else {
                mp[num]++;

                if (mp[num] > maxV)
                {
                    maxE = num;
                    maxV = mp[num];
                }
            }
        }

        if (maxV >= 3) cout << maxE << endl;
        else cout << -1 << endl;
    }

    return 0;
}