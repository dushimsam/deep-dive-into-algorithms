#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define  

int main(){
    // direct initialization
 vector<int> arr ={1,2,3,4,5,6,7,8,9,10,11};
 arr.push_back(12);


 for(int i :arr){
     cout<<i<<endl;
 }

     int input;
    string inputString;
    string str="samuel";
    
    cin >> input >> inputString;
    cout<< "Input name "<< inputString <<" input int "<<input<<"\n";

    return 0;
}