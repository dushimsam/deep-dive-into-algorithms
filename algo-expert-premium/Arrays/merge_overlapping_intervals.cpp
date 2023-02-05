#include<bits/stdc++.h>
typedef vector<int> vi;
typedef vector<vector<int>>;
using namespace std;


vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {

  vii res;
  sort(intervals.begin(),intervals.end());

  int currEndI = 0;
  res.push_back({intervals[0][0], intervals[currEndI][1]});

  for(int i=1;i<intervals.size();i++){
    if(intervals[i][0] <= intervals[currEndI][1]){
      if(intervals[currEndI][1] < intervals[i][1]){
        currEndI = i;
        res[res.size()-1][1] = intervals[currEndI][1];
      }
    }else{
      res.push_back({intervals[i][0],intervals[i][1]});
      currEndI = i;
    }
  }
  
  return res;
}

int main(){


    return 0;
}