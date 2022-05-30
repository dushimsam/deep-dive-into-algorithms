#include<bits/stdc++.h>
using namespace std;

    int combinationSum4(vector<int>& nums, int target) {
       int rows = nums.size();
       int cols = target + 1;
    
    vector<vector<int>> dp_matrix(rows,vector<int>(cols,0));

      // fill the first column        
      for(int i=0;i<rows;i++){
        dp_matrix[i][0] = 1;
      }
        
    for(int i=0;i < rows ; i++){
        for(int j=1;j<cols;j++){
            
         int prev_elem = i > 0 ? dp_matrix[i-1][j] : 0;
         
         if(j < nums[i]){
             dp_matrix[i][j] = prev_elem;
                 }else{
            dp_matrix[i][j] = prev_elem + dp_matrix[i][j - nums[i]];
         }
        }
    }
       return dp_matrix[rows-1][cols];
    }


int main(){
 vector<int> nums = {1,2,3};
 int target = 4;
 cout<<combinationSum4(nums,target);

    return 0;
}