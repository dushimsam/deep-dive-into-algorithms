#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string S;
  cin >> S;
  unordered_map<char, int> mp;
  for(char ch: S){
    mp[ch]++;
  }
  
  bool found = false;
  char oddChar;
  for(auto val:mp){
    if(val.second&1){
      if(!found){
        oddChar = val.first;
        found = true;
      }else{
        cout<<"NO SOLUTION\n";
        return 0;
      }
    }
  }
  string res;
  for(auto val:mp){
    for(int i = 1; i <= val.second/2; i++){
      res+=val.first;
    }
  }
  string temp = res;
  if(found)
   res+=oddChar;
   
  reverse(temp.begin(), temp.end());
  res += temp;
  cout<< res << "\n";
  return 0;
}