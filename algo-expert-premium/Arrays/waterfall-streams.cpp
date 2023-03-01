#include<bits/stdc++.h>

typedef vector<double> vd;

using namespace std;

vector<double> waterfallStreams(vector<vector<double>> array, int source)
{
  
    vd rowAbove = array[0];
    rowAbove[source] = -1;

     for(vd row : array){
       vd currRow = row;
       for(int i=0; i < rowAbove.size(); i++){
            // check if the row above has water, if not so continue,
         
          if(rowAbove[i] >= 0) continue;
         
            // if so check if there's no block at the current cell
            // if not so, assign the above value to be same as the curr one.
          if(currRow[i] != 1){
            currRow[i] += rowAbove[i];
            continue;
          }

          // if there's block, traverse to the left and right - hunting for a free space to place a split water
          // make the rowAbove point to the currentRow.
         double splitWaterVal = rowAbove[i] / 2;
          int rightIdx = i+1;
         while(rightIdx < rowAbove.size()){
           if(rowAbove[rightIdx] == 1.0) break;
           if(currRow[rightIdx] != 1){
             currRow[rightIdx] += splitWaterVal;
             break;
           }
           rightIdx++;
         }
           int leftIdx = i-1;

         while(leftIdx >= 0){
           if(rowAbove[leftIdx] == 1) break;
           if(currRow[leftIdx] != 1){
             currRow[leftIdx] += splitWaterVal;
             break;
           }
           leftIdx--;
         }

      }
      rowAbove = currRow; 
     }

    vd finalPercentages(rowAbove.size(), 0);

    for(int i = 0; i < rowAbove.size();i++){
        finalPercentages[i] = rowAbove[i] * -100;
    }
    return finalPercentages;
}


int main(){


    return 0;
}