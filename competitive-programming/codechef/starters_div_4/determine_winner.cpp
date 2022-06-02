#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main() {


    int t;
    cin >> t;
    while (t--) {
          int n = 4;
          vi arr;

          while(n--){
              int num;
            cin >> num;
            arr.push_back(num);
          }

          int max_1 = max(arr[0],arr[1]);
          int max_2 = max(arr[2],arr[3]);

          if(max_1 < max_2){
              cout<<"P"<<"\n";
          }else if(max_2 < max_1){
              cout<<"Q"<<"\n";
          }else{
              cout<<"TIE"<<"\n";
          }
    }
    return 0;
}