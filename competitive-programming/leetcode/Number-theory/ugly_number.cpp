#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll lcm(ll a, ll b) {
    return (a * b)/__gcd(a, b);
}

ll fn (ll a , ll b , ll c , ll x){
    return (x/a) + (x/b) + (x/c) - x/lcm(a,b) - x/lcm(a,c) - x/lcm(b,c) + x/lcm(a,lcm(b,c));
}

int findUglyNumber(int a, int b, int c, int n) {

    ll low = 0;
    ll high = 2e9;

    while (low < (high-1)) {
        ll mid = (low+high)/2;
        
        if(fn(a,b,c,mid) < n) low =mid;
        else high = mid;
    }

    return high;
}

int main() {
int  n = 3, a = 2, b = 3, c = 5;

cout<<findUglyNumber(a,b,c,n);
    return 0;
}