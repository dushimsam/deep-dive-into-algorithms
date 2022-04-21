#include<bits/stdc++.h>
using namespace std;

string findDivision(int rating){
    if(rating >= 1900) return "Division 1";
    else if(rating >= 1600 && rating <= 1899) return "Division 2";
    else if(rating >= 1400 && rating <= 1599) return "Division 3";
    else return "Division 4";
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int rating;
        cin >> rating;
        cout<<findDivision(rating)<<endl;
    }
    return 0;
}