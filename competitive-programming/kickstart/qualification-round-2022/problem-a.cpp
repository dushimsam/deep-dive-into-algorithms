#include <bits/stdc++.h>
using namespace std;

int getRemainder(vector<int> data,int kids){
    int sum =0;
    for(int i=0;i<data.size();i++)
        sum += data[i];
      
    int rem = sum % kids;
   
     return rem;
}

int main(){
int t;
cin >> t;
for(int i=1;i<=t;i++){
    int bags, kids;
    cin >> bags;
    cin >> kids;

    vector<int> data;
    
    while(bags--){
        int d;
        cin >> d;
        data.push_back(d);
    }
    cout << "Case #" << i << ": ";
    cout<<getRemainder(data,kids)<<endl;
}

return 0;
}