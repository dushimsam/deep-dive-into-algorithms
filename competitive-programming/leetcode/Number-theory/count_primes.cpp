#include<bits/stdc++.h>
using namespace std;



int countPrimeNumbers(int n){
  if(n <= 2) return 0;

  vector<int> sieve(n,0);
  sieve[0] = 1;
  sieve[1] = 1;

  for(int x=2;x<n;x++){
     if(sieve[x])continue;
     for(int u=x*2;u<n;u+=x){ 
         sieve[u] = x;
     }
  }

  int count = 0;
  for(int i=2;i<n;i++)if(!sieve[i])count++;

  return count;
}
int main(){
    int n = 10;
    cout<<countPrimeNumbers(n);

    return 0;
}