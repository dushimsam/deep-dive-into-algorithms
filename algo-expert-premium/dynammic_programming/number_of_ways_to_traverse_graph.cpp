#include<bits/stdc++.h>
using namespace std;


int numberOfWaysToTraverseGraph(int width, int height) {
  vector<vector<int>> res(height,vector<int>(width,0));
   for(int i=0; i < height; i++) res[i][0] = 1;
   for(int j=0; j < width; j++) res[0][j] = 1;
    
  for(int i=1; i < height; i++){
    for(int j=1; j < width; j++){
        res[i][j] = res[i-1][j] + res[i][j-1];
    }
  }
 
  return res[height-1][width-1];
}

int main(){
   int width = 4;
   int height = 3;
   
   // expected - 10
   cout<< numberOfWaysToTraverseGraph(width, height)<< endl;

    return 0;
}