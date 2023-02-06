#include <vector>
typedef vector<vector<int>> vii;
typedef vector<int> vi;

using namespace std;


vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {

  unordered_map<int,vii> mp;
  vii res;

  for(int i=0; i< array.size()-1; i++){
    for(int j = i+1; j< array.size(); j++){
       int diff = targetSum - (array[i] + array[j]);
       if(mp.find(diff) != mp.end()){
         for(vi pair:mp[diff]){
           pair.push_back(array[i]);
           pair.push_back(array[j]);
           res.push_back(pair);
         }
       }
    }
    for(int k=0; k < i; k++){
       int currSum = array[i] + array[k];
      if(mp.find(currSum) == mp.end()){
        mp[currSum] = vii{{array[i],array[k]}};
      }else{
        mp[currSum].push_back({array[i],array[k]});
      }
    }
  }
  
  return res;
}

int main(){

    vi arr = {7, 6, 4, -1, 1, 2};
    int targetSum = 16;


    return 0;
}