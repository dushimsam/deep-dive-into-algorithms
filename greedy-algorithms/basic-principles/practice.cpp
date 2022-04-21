#include <bits/stdc++.h>
using namespace std;


int findMaxVenom(string input) {
  map<char, int> mp;
  string snake = "SNAKE";

  for (int i = 0;i < snake.length();i++) {
    mp[snake[i]] = 0;
  }

  int minE = INT_MAX;
  int curr = 0;

  for (int i = 0;i < input.length();i++) {
    if (input[i] == snake[curr + 1] && mp[snake[curr]] > 0) {
      minE = min(mp[snake[curr]], minE);
      curr++;
      mp[snake[curr + 1]] += 1;
    }
    else if (input[i] == snake[curr]) {
      if (mp[curr] < minE)
        mp[snake[curr]] += 1;
    }
  }

  return minE == INT_MAX ? 0 : minE;
}


int main() {
   map<int,int> mp;
   mp[2] = 1;
   cout<<mp[2];
  return 0;
}