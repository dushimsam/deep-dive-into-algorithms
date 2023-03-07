#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;

vi getDistanceFromEachBlock(vector<unordered_map<string, bool>> blocks, string req){
  vi distancesFromEachBlock(blocks.size());
  int closestIdx= INT_MAX;

  // Fill distances from left to right
  for(int i=0; i < blocks.size(); i++){
    if(blocks[i][req])
      closestIdx = i;
    distancesFromEachBlock[i] = abs(closestIdx - i);
  }

  // fill distances from right to left
  for(int i= blocks.size()-1; i >= 0; i--){
    if(blocks[i][req]) closestIdx = i;
    distancesFromEachBlock[i] = min(abs(closestIdx - i), distancesFromEachBlock[i]);
  }

  return distancesFromEachBlock;
}

vi getMaxDistancesFromEachBlock(vector<unordered_map<string, bool>> blocks, vii distancesFromEachBlock){
  vi maxDistancesFromEachBlock(blocks.size());
  
  for(int i=0; i < blocks.size(); i++){
    vi distancesFromCurrBlock;
    for(vi distance: distancesFromEachBlock){
      distancesFromCurrBlock.push_back(distance[i]);
    }
    maxDistancesFromEachBlock[i] = *max_element(distancesFromCurrBlock.begin(), distancesFromCurrBlock.end()); 
  }
  return maxDistancesFromEachBlock;
}

int getIndexWithMinDistance(vi maxDistancesFromEachBlock){
  int idx = 0;
  int smallestEl = maxDistancesFromEachBlock[0];
  for(int i=1; i< maxDistancesFromEachBlock.size(); i++){
   if(maxDistancesFromEachBlock[i] < smallestEl){
     smallestEl = maxDistancesFromEachBlock[i];
     idx = i;
   }
  }
  return idx;
}
int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
  // Get distances from blocks
  vii distancesFromEachBlock;
  for(string req: reqs){
      distancesFromEachBlock.push_back(getDistanceFromEachBlock(blocks,req));  
  }
  // Get maxDistances From each block
  vi maxDistancesFromEachBlock = getMaxDistancesFromEachBlock(blocks, distancesFromEachBlock);
  // Get index with smallest ditance
  return getIndexWithMinDistance(maxDistancesFromEachBlock);
}

int main(){
    
}