#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> arr){
     int n = arr.size();

     for(int i=0;i<n-2;i++){
         int minE=arr[i];
         int minI = 0;

         for(int j=i+1;j<n-1;j++){
            if(arr[j] < minE){
                minE = arr[j];
                minI = j;
            }
         }
         //swap
         int t = arr[i];
         arr[i] = arr[minI];
         arr[minI] = t;
     }
}




int main(){
   



    return 0;
}