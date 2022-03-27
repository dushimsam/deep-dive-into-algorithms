#include<bits/stdc++.h>
using namespace std;

int findMinLastStoneWeight(vector<int> stone_weights){
    int sum = 0;
    int n = stone_weights.size();
    for(int i=0;i<n;i++) sum += stone_weights[i];
    
    int target = sum / 2;
    vector<int> dp(target+1);

    for(int i=0;i<n;i++){
         for(int j=target;j >= stone_weights[i];j--){
             dp[j] = max(dp[j],dp[j-stone_weights[i]]+stone_weights[i]);
         }
    }

    return sum - (dp[target] * 2);
}

int main(){


    return 0;
}