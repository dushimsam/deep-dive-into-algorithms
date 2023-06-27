#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

string smallestSubstringContaining(string bigString, string smallString) {
  int leftIdx = 0;
  int rightIdx = 0;
  vi smallestRange={0, INT_MAX};
  unordered_map<char, int> mp;
  unordered_map<char, int> temp_mp;
  int counted=0;
  
  for(char ch:smallString){
    if(mp.find(ch) == mp.end()){
      mp[ch] = 1;
    }else{
      mp[ch]++;
    }
  }
  

  while(rightIdx < bigString.length()){
     char currCh = bigString[rightIdx];
    
     if(mp.find(currCh) == mp.end()){
       continue;
     }

    if(temp_mp.find(currCh) == temp_mp.end()){
      temp_mp[currCh] = 1;
    }else{
      temp_mp[currCh]++;
    }

    if(temp_mp[currCh] == mp[currCh])
       counted++;

    while(counted == mp.size() && leftIdx <= rightIdx){
        leftIdx++;
        if(mp.find(bigString[leftIdx]) == mp.end()){
              continue;
          }
      
          temp_mp[bigString[leftIdx]]--;
          counted--;
    }

    smallestRange = smallestRange[1] - smallestRange[0] < rightIdx - leftIdx ?
    smallestRange: vector<int> {leftIdx-1, rightIdx};
    
    rightIdx++;
  }

  if(smallestRange[1] == INT_MAX) return "";
  
  return bigString.substr(smallestRange[0], smallestRange[1] - smallestRange[0]);
}
