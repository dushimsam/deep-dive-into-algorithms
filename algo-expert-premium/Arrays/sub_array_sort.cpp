#include<bits/stdc++.h>

using namespace std;


// Find the part of the array at which the ascending sorting should be revised.

vector<int> subarraySort(vector<int> array) {
   int maxOutOfOrder = -1;
   int minOutOfOrder = -1;

  for(int i = 1; i < array.size(); i++){

    if(array[i] < array[i-1]){
       maxOutOfOrder = maxOutOfOrder == -1 ? array[i-1] : max(maxOutOfOrder, array[i-1]);
       minOutOfOrder = minOutOfOrder == -1 ? array[i] : min(minOutOfOrder, array[i]);
    }
  }



  if(maxOutOfOrder == -1) return {-1,-1};

  int i = 0;
  while(minOutOfOrder >= array[i]){
    i++;
  }
  int j = array.size()-1;
  while(maxOutOfOrder <= array[j]){
    j--;
  }
  
  return {i,j};
}


int main(){



    return 0;
}