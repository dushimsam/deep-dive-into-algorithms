#include <bits/stdc++.h>
using namespace std;

int solve(int num, int k) {

    for (int i = 0; i < k; i++) {
        if (num % 10 == 0) {
            num /= 10;
        }
        else {
            num--;
        }
    }
    return num;
}
int main() {

    int num, k;
    cin >> num;
    cin >> k;
    cout << solve(num, k);
    return 0;
}