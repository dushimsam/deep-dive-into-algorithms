#include<bits/stdc++.h>
using namespace std;
typedef priority_queue<int> pq;
typedef vector<int> vi;

int solve(vi arr,int n1,int n2){
    sort(arr.begin(),arr.end());
    vi arr2;

    int sum = 0;
    for(int i=arr.size()-1;i >= (arr.size()-n2);i--) sum+=arr[i];

    return sum;
}


int main() {
    int n, q;
    
    cin >> n;
    cin >> q;
    
    pq arr;
     
    while (n--) {
        int num;
        cin >> num;
        arr.push(num);
    }

    while (q--) {
      int n1,n2;
      cin >> n1;
      cin >> n2;

      cout<< solve(arr,n1,n2)<<"\n";
    }
    return 0;
}