#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int main() {
    vi arr={34,6,7,8,8};
    sort(arr.begin(),arr.end());

    for(int e : arr){
        cout<<e<<endl;
    }

    return 0;
}