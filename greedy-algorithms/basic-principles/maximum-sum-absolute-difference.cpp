#include <bits/stdc++.h>
using namespace std;

// THE BEST APPROACH EVER 😂😂😂😂😂😂😂😂 O((n*n/2)log(n))

int maximumSumAbsDiff(vector<int> arr,int n){
   int half = n/2;
   int sum = 0;
   int j=n-1;
   int half_counter = half-1;
 
   sort(arr.begin(),arr.end());

   for(int i =0;i < half; i++){
     int diff_1 = abs(arr[i] - arr[j]);
     cout<<arr[i]<<" - " <<arr[j]<<" : "<<diff_1<<"\n";
     int diff_2 = abs(arr[j] - arr[half_counter]);
     cout<<arr[j]<<" - " <<arr[half_counter]<<" : "<<diff_2<<"\n";

     sum += (diff_1 + diff_2);
     
    j--;
    half_counter--;
   }

   return sum;
}
int main(){

   vector<int> arr = {1 , 3, 5, 6, 7,  9};
   cout << maximumSumAbsDiff(arr,arr.size());

    return 0;
}