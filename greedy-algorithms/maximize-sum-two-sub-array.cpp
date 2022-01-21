#include<bits/stdc++.h>
using namespace std;


int maximize_difference(vector<int> arr,int k){
    // REDEFINE 
     sort(arr.begin(),arr.end());
    
    int sum1 =0;
    for(int i=0;i<k;i++){
        sum1 +=arr[i];
    }

    int sum2=0;
    for(int i=k;i<arr.size();i++){
        sum2+=arr[i];
    }
    
    return abs(sum1-sum2);
}
int main(){

 vector<int> arr ={1, 1, 1, 1, 1, 1, 1, 1};
cout<<maximize_difference(arr,3);
    return 0;
}