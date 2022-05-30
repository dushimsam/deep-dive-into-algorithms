#include<bits/stdc++.h>
using namespace std;

/***
 
In a deck of cards, each card has an integer written on it.
Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
Each group has exactly X cards.
All the cards in each group have the same integer.


Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.


APPROACH-> 

1. Use map for assigning the corresponding count of each item.
2. CHECK TWO CONDITIONS BEFORE YOU MARK AS TRUE
   for(auto i : map) gcd(val,i.second)
   if(val < 2) return false;

   for(auto i : map) if(val % i.second != 0) return false;
   
   return true
***/
bool solve(vector<int> arr) {
    map<int, int> mp;

    for (int i : arr)
        mp[i]++;
    
    
    int val = mp[arr[0]];
  
    // CONDITION ONE 
    for(auto i : mp) val=__gcd(val,i.second);

    if(val < 2) return false;

    for(auto i : mp) if(i.second % val != 0) return false;
   
    return true;
}

int main() {
    vector<int> deck = { 1,2,3,4,4,3,2,1 };
    cout<< solve(deck);
    return 0;
}