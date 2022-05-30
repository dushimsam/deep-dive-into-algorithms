#include<bits/stdc++.h>
using namespace std;

int possibleCombinationToFormSum(vector<int> set,int target){
        vector<unsigned long long int> dp(target+1);
        dp[0] = 1;
        for(int i=1; i<= target ; i++ ){
            for(int e: set){
                if(i >= e){
                    dp[i] += dp[i - e];
                }
            }
        }
        return dp[target];
}
int main(){


    return 0;
}