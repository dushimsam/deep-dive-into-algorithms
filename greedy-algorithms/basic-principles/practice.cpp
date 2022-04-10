#include <iostream>
using namespace std;

int main() {
//   std::cin.tie(nullptr);
//   std::ios_base::sync_with_stdio(false);
    int  N;
  cin >> N;
 unsigned int res = 2;
  for(int i=2;i<=N;i++){
      res *= 2;
  }
  cout<<res;
  return 0;
}