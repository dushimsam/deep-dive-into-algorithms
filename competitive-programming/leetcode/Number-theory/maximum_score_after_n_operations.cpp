#include<bits/stdc++.h>
using namespace std;

int maximumScore(vector<int> nums){
    if(nums.size() < 2) return 0;

    sort(nums.begin(), nums.end());
    deque<int> dq;
    int ops = nums.size() / 2;
    
    for(int i = 0; i < nums.size() && ops > 0;i++){
        
        int j;
        for(j = (nums.size() - 1); j > i; j--){
            
        }
    }
  
}


int main(){



    return 0;
}