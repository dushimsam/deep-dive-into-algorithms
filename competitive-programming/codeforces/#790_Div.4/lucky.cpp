#include<bits/stdc++.h>
using namespace std;

string solve(string num) {

    int front_sum = 0;
    int back_sum = 0;

    for (int i = 0;i < 3;i++) {
        front_sum += (int)num[i];
    }

    int size = num.size();

    for (int i = (size - 1);i >= (size - 3);i--) {
        back_sum += (int)num[i];
    }

    if (front_sum == back_sum) return "YES";
    else return "NO";
}
int main() {

    int t;
    cin >> t;

    while (t--) {
        string num;
        cin >> num;
        cout << solve(num) << endl;
    }
    return 0;
}