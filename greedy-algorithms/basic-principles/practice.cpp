#include <bits/stdc++.h>
using namespace std;

void solve(string in) {
  int size = in.length();
  if (size > 10) {
    cout << in.at(0) << size - 2 << in.at(size - 1) << "\n";
  }
  else {
    cout << in << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  
  while (t--) {
    string in;
    cin >> in;
    solve(in);
  }

  return 0;
}