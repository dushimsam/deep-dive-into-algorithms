#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow10(ll x){
  ll res = 1;
  
  for(int i = 1; i <= x; i++){
    res *=10;
  }
  return res;
}

ll solve(ll K){
  if(K < 9)
    return K + 1;

  ll len = 1;
  while((len * 9 * pow10(len-1)) < K){
    K -= len * 9 * pow10(len-1);
    len++;
  }

  string S = to_string(pow10(len -1) + K/len);
  return int(S[K % len] - '0');
}


int main(){
   ll N, K;
   cin >> N;
   while(N--){
    cin >> K;
    cout << solve(K-1)<<"\n";
   }
    return 0;
}