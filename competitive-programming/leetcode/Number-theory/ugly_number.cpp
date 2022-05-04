#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli lcm(int a, int b) {
    return (lli)a *(b /__gcd(a, b));
}

int findUglyNumber(int a, int b, int c, int n) {
    lli low = 1;
    lli high = INT_MAX;
    lli o = 0;

    while (low < high) {
        lli mid = (high + low) / 2;

        o = (int)((mid / a) + (mid / b) + (mid / c) - (mid / lcm(a, b)) - (mid / lcm(b, c)) - (mid / lcm(a, c)) + (mid / lcm(a, lcm(b, c))));
    
        if (o < n) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }

    return (int)low;
}
int main() {
int  n = 3, a = 2, b = 3, c = 5;

cout<<findUglyNumber(a,b,c,n);
    return 0;
}