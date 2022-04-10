#include<bits/stdc++.h>
using namespace std;




int main(){

    string s ="mystring";
    string r;

    for(int i=s.length()-1;i >= 0;i--){
         r.push_back(s[i]);
    }
    cout<<"Reversed String "<<r;
}