#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int solve(vi arr, int m) {
    int sum = 0;
    for (int i = 0;i < arr.size();i++) {
        sum += arr[i];
    }

    int diff = m - sum;

    if (diff < 0) {
        return abs(diff);
    }
    return 0;
}

int main() {
    int t;

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        cin >> m;

        vi arr;

        while (n--) {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        cout << solve(arr,m) << "\n";
    }
    return 0;
}