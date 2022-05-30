#include<bits/stdc++.h>
using namespace std;

int sumConsecutiveDifferences(vector<int> arr) {

    sort(arr.begin(), arr.end());
    int half = arr.size() / 2;
    int j = arr.size() - 1;
    int sum = 0;
    int i=0;

    while(i <= half) {
       
        if (i == j)
        {
            sum += abs(arr[i] - arr[0]);
            return sum;
        }
        else
        {
            sum += abs(arr[i] - arr[j]);
        }
        i++;

        if(i == j){
            sum += abs(arr[j] - arr[0]);
           return sum;
        }else{
            sum += abs(arr[j] - arr[i]);
        }
        j--;
    }
    return sum;
}


int main() {
    vector<int> arr = { 10, 12, 15 };
    cout << sumConsecutiveDifferences(arr) << "\n";
    //

    // vector<int> arr1 ={ 10, 12, 15 };
    // cout << sumConsecutiveDifferences(arr1) <<"\n";

    return 0;
}