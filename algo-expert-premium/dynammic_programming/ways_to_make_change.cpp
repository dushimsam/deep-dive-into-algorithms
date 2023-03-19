#include<bits/stdc++.h>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  vector<int> ways(n+1,0);
  ways[0] = 1;

for(int denom: denoms){
  for(int amount = 1; amount <= n; amount++){
      if(denom <= amount){
        ways[amount] += ways[amount-denom];
      }
    }
  }
  return ways[n];
}

int main(){

vector<int> denoms = {1, 5};
int amount = 6;

// expected result - 2

cout << numberOfWaysToMakeChange(amount, denoms) << "\n";
return 0;
}


