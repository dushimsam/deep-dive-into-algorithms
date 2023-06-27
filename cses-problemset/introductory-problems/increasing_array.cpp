#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, currN, totalDiff = 0;
    cin >> n;
    vector<long long> arr;
     
    while(n--){
        cin >> currN;
        arr.push_back(currN);
    }

    for(long long i = 1; i < arr.size(); i++){
       if(arr[i] < arr[i - 1]){
        totalDiff += arr[i - 1] - arr[i];
        arr[i] = arr[i - 1];
       }
    }
    cout << totalDiff << endl;
    return 0;
}