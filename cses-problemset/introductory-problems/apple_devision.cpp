#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);

    for(int i = 0; i < n; i++){
      int num;
      cin >> num;
      arr[i] = num;
    }

    ll minDiff = INT_MAX;

    for(int i = 0; i < (1<<n); i++){
      ll a = 0, b = 0;
      for(int j = 0; j < n; j++){
        if(i&(1<<j)){
          a += arr[j];
        } else {
          b += arr[j];
        }
      }
      minDiff = min(minDiff, abs(a-b));
    }
    cout << minDiff << "\n";

    return 0;
}